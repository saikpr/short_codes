/*input
cpus 10
job 1 1 orderProcessor BExvg 1 1
job 1 2 orderProcessor XfGie 2 2
assign 2 1
job 10 1 marketDataProcessor QfyIRX 100 100
assign 10 2
query 1 2
query 2 1
query 11 0
query 3 orderProcessor
*/
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <unordered_map>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <cassert>
using namespace std;

typedef long long int time_type ; //custom, name might coincide with one defined in time.h
typedef long long int id_type;
typedef int imp_type;
typedef long long int cpucount_type;
typedef long long int jobcount_type;


class Job{
    time_type timestamp,duration;
    id_type id;
    string origin,instruction;
    imp_type imp;
    //static int assign=0;  
    public:
        time_type assigned_time;
        Job(time_type ts,id_type id,string orig,string inst,imp_type imp,time_type duration):assigned_time(-1)
        {

            this->timestamp=ts;
            this->id=id;
            this->duration=duration;
            this->origin=orig;
            this->instruction=inst;
            this->imp=imp;
        }

    time_type getTs() const{
        return this->timestamp;
    }   
    id_type getId() const{
        return this->id;
    }   
    time_type getDuration() const{
        return this->duration;
    }   
    imp_type getImp() const{
        return this->imp;
    }       
    string getOrig() const{
        return this->origin;
    }   
    string getInst() const{
        return this->instruction;
    }   

    void printJob() const
    {
        cout<<"job "<<timestamp<<" "<<id<<" "<<origin<<" "<<instruction<<" "<<imp<<" "<<duration<<endl;
        
    }
};

class Compare
{
public:
    bool isGreater(Job *A, Job *B)
    {
        if(A->getImp()!=B->getImp())
            return A->getImp()<B->getImp();
       
        else if(A->getTs()!=B->getTs())
            return A->getTs()>B->getTs();
       
        else
            return A->getDuration()>B->getDuration();
    }
    bool operator() (Job * A, Job *B)
    {
       return isGreater(A,B);
    }
};

class NegativeCompare:public Compare
{
    public:
    bool operator() (Job * A, Job *B)
    {
        return !isGreater(A,B);
    }
};

typedef tuple<time_type, jobcount_type, vector<Job*>  > state_delta_type;
typedef priority_queue<Job *,std::vector<Job *>,Compare> job_priority_queue_type;

typedef set < Job * ,NegativeCompare > jobmap_type;


class CPUCounter
{
    

    priority_queue<cpucount_type,std::vector<cpucount_type>,std::greater<cpucount_type> > cpuQueue;
    unordered_map<time_type,cpucount_type> cpuQueueMap;

    protected:
    cpucount_type cpu_avail_count,starting_cpu;

    cpucount_type getAvailableCPUCount(time_type timestamp)
    {
        time_type temp_deadline; 

        while(cpuQueue.empty()==false && cpuQueue.top()<=timestamp)
        {
            temp_deadline = cpuQueue.top();
            cpu_avail_count += cpuQueueMap[temp_deadline];
            
            cpuQueueMap.erase(temp_deadline);
            cpuQueue.pop();

        }
        return this->cpu_avail_count;
    }

    void addCPUBusy(time_type deadline)
    {

        if (cpuQueueMap.count(deadline)==1)
        {
            cpuQueueMap[deadline]++;
        }
        else
        {
            cpuQueue.push(deadline);
            cpuQueueMap[deadline] = 1;

        }
        cpu_avail_count--;
    }
    public:
        CPUCounter(cpucount_type cpu_init): cpu_avail_count(cpu_init),starting_cpu(cpu_init)
        {}

        bool check_valid_cpu_state()
        {
            cpucount_type temp=cpu_avail_count;

            for(auto it = cpuQueueMap.begin();it!=cpuQueueMap.end();++it)
            {
                temp += (*it).second;
            }
            return temp==starting_cpu;
        }

};


class QueueProcessor : public CPUCounter{

    deque <state_delta_type> delta_changes;

    job_priority_queue_type assign_queue;
    
    jobmap_type queryType1_queue;

    unordered_map <string , jobmap_type > origin_job_map_query2;

    size_t index_query1,index_query2;
    // queryType2_queue;

public:
    QueueProcessor(cpucount_type cpu) : CPUCounter(cpu),index_query1(0),index_query2(0)
    {
    }
    void addJobToQueue(time_type ts,id_type id,string orig,string inst,imp_type imp,time_type duration);

    void assignJobs(time_type ts,jobcount_type k_jobs);

    void updateStateQuery1(time_type ts);
    void updateStateQuery2(time_type ts);

    void queryJobsType1(time_type ts,jobcount_type k_jobs);

    void queryJobsType2(time_type ts,string orig);

    void cleanUpJobs(); //when both query1 and query2 have been performed

};

void QueueProcessor::addJobToQueue(time_type ts,id_type id,string orig,string inst,imp_type imp,time_type duration)
{
    Job * incomingJob = new Job(ts,id,orig,inst,imp,duration);
    assign_queue.push(incomingJob);
    if (delta_changes.size()!= 0 && get<0>(delta_changes[delta_changes.size()-1]) == ts)
    {
        state_delta_type &last_state = delta_changes[delta_changes.size()-1];
        get<2>(last_state).push_back(incomingJob);
    }
    else
    {
        state_delta_type state_delta ;
        get<0>(state_delta) = ts;
        get<1>(state_delta) = 0;
        get<2>(state_delta).push_back(incomingJob);
        delta_changes.push_back(state_delta);
    }


}

void QueueProcessor::assignJobs(time_type ts,jobcount_type k_jobs)
{
    assert(check_valid_cpu_state()==true);
    cpucount_type cpus_available = getAvailableCPUCount(ts);
    jobcount_type jobs_in_queue = (jobcount_type)assign_queue.size();

    jobcount_type jobs_to_remove = min({cpus_available,jobs_in_queue,k_jobs});
    // assert(jobs_to_remove>0);
    if (delta_changes.size()!= 0 && get<0>(delta_changes[delta_changes.size()-1]) == ts)
    {
        state_delta_type &last_state = delta_changes[delta_changes.size()-1];
        get<1>(last_state) = get<1>(last_state)+jobs_to_remove;
    }
    else
    {
        state_delta_type state_delta ;
        get<0>(state_delta) = ts;
        get<1>(state_delta) = jobs_to_remove;
        get<2>(state_delta) = vector<Job*>();
        delta_changes.push_back(state_delta);
    }

    while(jobs_to_remove-->0)
    {
        Job * temp = assign_queue.top();
        if (temp->getDuration()!=0)
            addCPUBusy(ts+temp->getDuration());
        assign_queue.pop();
        temp->assigned_time = ts;
        temp->printJob();
        // jobs_to_remove--;
    }


}

void QueueProcessor::cleanUpJobs() //TODO
{
    // time_type min_valid_time = min(index_query1,index_query2);


    // while(min_valid_time-->0)
    // {
    //     index_query1--;
    //     index_query2--;
    //     delta_changes.pop_front();
    // }
}
void QueueProcessor::updateStateQuery1(time_type ts)
{
    // cout<<"updateStateQuery1 :"<<ts<<endl;
    while(index_query1<delta_changes.size()&&get<0>(delta_changes[index_query1])<=ts)
    {
        state_delta_type this_state = delta_changes[index_query1];


        // cout<<get<2>(this_state).size()<<endl;


        for(auto it=get<2>(this_state).begin();it!=get<2>(this_state).end();++it)
        {
            queryType1_queue.insert(*it);
        }

        auto temp_it = queryType1_queue.begin();
        int incr_it = get<1>(this_state);
        while(incr_it>0)
        {
            temp_it++;
            incr_it--;
        }
        queryType1_queue.erase(queryType1_queue.begin(),temp_it );
        index_query1++;
        // delta_changes[index_query1] = this_state; 
        // cout<<get<2>(this_state).size()<<endl;
    }
}


void QueueProcessor::queryJobsType1(time_type ts,jobcount_type k_jobs)
{
    updateStateQuery1(ts);

    jobcount_type  incr_it = min((jobcount_type)queryType1_queue.size(),k_jobs);
    if(incr_it == 0)
    {
        return;
    }
    auto temp_it = queryType1_queue.begin();
    while(incr_it>0)
    {
        temp_it++;
        incr_it--;
    }

    for(auto it =queryType1_queue.begin();it!=temp_it;it++)
    {
        (*it)->printJob();
    }

}



void QueueProcessor::updateStateQuery2(time_type ts)
{
    // cout<<"updateStateQuery2 :"<<ts<<" "<<get<0>(delta_changes[index_query2])<<endl;
    while(index_query2<delta_changes.size()&&get<0>(delta_changes[index_query2])<=ts)
    {
        state_delta_type &this_state = delta_changes[index_query2];
        // cout<<get<0>(this_state)<<" "<<get<1>(this_state)<<" "<<get<2>(this_state).size()<<endl;
        for(auto it=get<2>(this_state).begin();it!=get<2>(this_state).end();++it)
        {
            origin_job_map_query2[(*it)->getOrig()].insert(*it);
        }
        
        index_query2++;
    }
}


void QueueProcessor::queryJobsType2(time_type ts,string orig)
{
    updateStateQuery2(ts);

    jobmap_type &temp_map =origin_job_map_query2[orig];
    for(auto it =temp_map.begin();it!=temp_map.end();it++)
    {
        if((*it)->assigned_time==-1 || (*it)->assigned_time>ts)
        {
            (*it)->printJob();
        }
        else
        {
            temp_map.erase((*it));
        }
    }

}



int main(){

    string command,orig,instruction,temp_orig;
    cpucount_type cpus;
    time_type timestamp,process_duration;
    id_type pid;
    imp_type importance_value;
    jobcount_type k_jobs;
    QueueProcessor Director(cpus);
    


    cin>>command;
    if (command == "cpus")
    {       
        cin>>cpus;
        Director = QueueProcessor(cpus);
    }
    while(cin>>command&&cin.eof()==false)
    {
        
        if (command =="job")   
        {
            cin>>timestamp>>pid>>orig>>instruction>>importance_value>>process_duration;
            Director.addJobToQueue(timestamp,pid,orig,instruction,importance_value,process_duration);
        }
        else if (command =="assign")
        {
            cin>>timestamp >>k_jobs;
            Director.assignJobs(timestamp,k_jobs);
            
            // cout<<"Not Implemented"<<endl;
        }
        else if (command =="query")
        {
            cin>>timestamp;
            
            cin >>temp_orig;
            stringstream ss(temp_orig);
            if((ss>>k_jobs).fail()==false)
            {
                Director.queryJobsType1(timestamp,k_jobs);
            }
            else
            {
                // ss>>temp_orig;
                // cout<<"Not Implemented"<<endl;
                Director.queryJobsType2(timestamp,temp_orig);
            }
            // cout<<"Not Implemented"<<endl
        }
        
        // cout<<"Instruction "<<command<<" Processed"<<endl;

    }
    




}

