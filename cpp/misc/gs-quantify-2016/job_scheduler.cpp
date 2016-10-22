/*input
cpus 10
job 1 1 orderProcessor BExvg 1 1
job 1 2 orderProcessor XfGie 2 2
assign 2 1
job 10 1 marketDataProcessor QfyIRX 100 100
assign 10 2
*/
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <unordered_map>
#include <utility>
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
		Job(time_type ts,id_type id,string orig,string inst,imp_type imp,time_type duration)
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

};

class Compare
{
public:
    bool operator() (Job * A, Job *B)
    {
       if(A->getImp()!=B->getImp())
       	return A->getImp()<B->getImp();
       
       else if(A->getTs()!=B->getTs())
       		return A->getTs()>B->getTs();
       
       else
       		return A->getDuration()>B->getDuration();
    }
};

typedef tuple<time_type, jobcount_type, vector<Job*>  > state_delta_type;
typedef priority_queue<Job *,std::vector<Job *>,Compare> queue_type;


class CPUCounter
{
	cpucount_type cpu_avail_count;

	priority_queue<cpucount_type,std::vector<cpucount_type>,std::greater<cpucount_type> > cpuQueue;
	unordered_map<time_type,cpucount_type> cpuQueueMap;

	public:
	CPUCounter(cpucount_type cpu_init): cpu_avail_count(cpu_init)
	{
	}

	cpucount_type getAvailableCount(time_type timestamp)
	{
		time_type temp_deadline; 
		while(cpuQueue.empty()==false && cpuQueue.top()<=timestamp)
		{
			temp_deadline = cpuQueue.top();
			cpu_avail_count +=cpuQueueMap[temp_deadline];
			cpuQueueMap.erase(temp_deadline);
			cpuQueue.pop();

		}
		return this->cpu_avail_count;
	}

	void addCpuDeadline(time_type deadline)
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
	}

};


class QueueProcessor : public CPUCounter{

	deque <state_delta_type> delta_changes;

	queue_type assign_queue, query1_queue, query2_queue;

public:
	QueueProcessor(cpucount_type cpu) : CPUCounter(cpu){
	}
	void addJobToQueue(time_type ts,id_type id,string orig,string inst,imp_type imp,time_type duration)
	{
		Job * incomingJob = Job(ts,id,orig,inst,imp,duration);
		assign_queue.push(incomingJob);
		if (delta_changes.size()!= 0 )
		{
			state_delta_type last_state = delta_changes[delta_changes.size()-1];

			if (get<0>(last_state) == ts)
			{
				get<2>(last_state).push_back(incomingJob);
				delta_changes.pop_back();
			    delta_changes.push_back(last_state);
			}
			
		}
		else
		{
			state_delta_type state_delta({ts,0,vector<Job*>(1,incomingJob)}) ;
			delta_changes.push_back(state_delta);
		}


	}
	// void insertInCpuQueue(long long int minimum,priority_queue<Job *,std::vector<Job *>,Compare> &jobsQueue){
	// 	Job * assignJob;
	// 	long long int minValue=minimum;

	// 	while(minValue--){
		
	// 	assignJob=jobsQueue.top();

	// 	cpuQueue.push(assignJob->getTs());
	// 	cpuQueueMap[assignJob->getTs()+assignJob->getDuration()]++;
		
	// 	printAssignedJob(assignJob);
		
	// 	pushToQueryDeque(assignJob->getTs(),jobsQueue);                    //Need to optimize

	// 	jobsQueue.pop();
		
	// 	}

	// 	updateCpu(cpu_available-minimum);
	// }

	// void printAssignedJob(Job* assignedJob){

	// 	cout<<"job "<<assignedJob->getTs()<<" "<<assignedJob->getId()<<" "<<assignedJob->getOrig()<<" "<<assignedJob->getInst()<<" "<<assignedJob->getImp()<<" "<<assignedJob->getDuration()<<endl;
	// 	return;
	// }

	

	


	// //Need to optimize
	// void pushToQueryDeque(long long int ts,priority_queue<Job *,std::vector<Job *>,Compare> jobsQueue){

	// 	pair<long long int,priority_queue<Job *,std::vector<Job *>,Compare> > temp;

	// 	temp.first=ts;
	// 	temp.second=jobsQueue;
	// 	queryDeque.push_back(temp);

	// }

	// void getQueryJobsQueue(long long int ts,long long int k){

	// 	long long int jobsQueueSize,minimum;
	// 	pair<long long int,priority_queue<Job *,std::vector<Job *>,Compare> > jobPair;

	// 	int c=0;
	// 	while(!queryDeque.empty() && queryDeque.front().first<=ts){
	// 		jobPair=queryDeque.front();
	// 		queryDeque.pop_front();
	// 		c=1;
	// 	}
 
	// 	if(c!=0){
	// 		jobsQueueSize=jobPair.second.size();
	// 	}
	// 	else
	// 		jobsQueueSize=0;

	// 	minimum=min(jobsQueueSize,k);

	// 	printQueryJobs(minimum,jobPair);

	// }
	// void printQueryJobs(long long int minimum,pair<long long int,priority_queue<Job *,std::vector<Job *>,Compare> > &jobPair){

	// 	priority_queue<Job *,std::vector<Job *>,Compare> jobsQueue=jobPair.second;
	// 	Job * job;
	// 	while(minimum--)
	// 	{
	// 		job=jobsQueue.top();
	// 		printAssignedJob(job);
	// 		jobsQueue.pop();
			
	// 	}

	// }


};


class Director{

	long long int cpu_initial,minimum;
	priority_queue<Job *,std::vector<Job *>,Compare> jobsQueue;
	
	public:
		Director(long long int cpu)
	{
		this->cpu_initial=cpu;
	}

	void insertInJobsQueue(Job * A){

		jobsQueue.push(A);
		cout<<jobsQueue.size()<<endl;

	}
	Job * getJob(){

		Job * A= jobsQueue.top();
		jobsQueue.pop();
		return A;

	}
	


	void assign(long long int ts,long long int k, CPU * cpuObject){

		long long int minimum=min(k,getJobsQueueSize());
		long long int effectiveCpu;
		if(minimum <=cpuObject->getCpuAvailable()){

			cpuObject->insertInCpuQueue(minimum,jobsQueue);

		}
		else{

			effectiveCpu=cpuObject->getEffectiveCpu(ts,minimum);
			minimum=(min(k,getJobsQueueSize()),effectiveCpu);
			cpuObject->insertInCpuQueue(minimum,jobsQueue);
		}
		

	}

	long long int getJobsQueueSize(){

		return jobsQueue.size();
	}

	void queryType1(long long int ts, long long int k, CPU *cpuObject){

		cpuObject->getQueryJobsQueue(ts,k);

	}

};


int main(){

	string command,orig,instruction;
	long long int cpu,ts,duration,id,k;
	int imp;
	cin>>command;

	if(command!="cpus"){
		cout<<"Invalid Input"<<endl;
		return 0;
	}
	else{

		cin>>cpu;
		Director *driver =new Director(cpu);
		CPU *cpuObject =new CPU(cpu);
		while(cin>>command){
		
			if(command=="job"){

				cin>>ts>>id>>orig>>instruction>>imp>>duration;
				Job * A=new Job(ts,id,orig,instruction,imp,duration);
				driver->insertInJobsQueue(A);
			}

			else if(command=="assign"){

				cin>>ts>>k;
				driver->assign(ts,k,cpuObject);
			}

			else if(command=="query"){
					cin>>ts>>k;
					driver->queryType1(ts,k,cpuObject);

			}


		}




	}




}

