'''input
1
87
JXCMISMKH XSOP
YVSLTHSQSTHQMQTER
GWNQ QPXBD QVQ
BTTA FSTEFBNQ W EO
MKV  WBRBPDAQOTR
RFDNC  LYLK RHC
AQNCDGJ GZN E NCW T
HNSKDFRFDQGLVAPB
DSLVXB RXPNEWVRKB
PSKL IWJA GBC
JXMKMVZ FAT JVTOG YR
CCFYBEZ  OANTCZKO
TZZ QOFXG CCXE R Z
TXKLH
NYCKJJWEFVVL GRRILCF
LZ P
OZRVRAP
CQUYVRHMVZSI
SUGXP
KNYQTMZCVRKCU OGRYOV
BJPG E
MOQS
YHEUKZHUTTI
MCR DTE
JC
OOEAY ZCBHESOQAEY W
IYA
TLBNUDLE
H
EDW EVYPFKPB DXJDJ
A EXEYTHVVOS
RCQOXK UNGWCBHLERF
IJTM AL
VZ JE RSO JECHSEII
FFI
GUJCUULEHINLHAWV
XSOBGKJYSO
PO W FYJR NYGSGGS TV
FOGQQA W
MGS
DYUEDSR RFEXPYE
HMMOS AKYWC UVCPH
TKZGIMDE SUCZUGE
EENSHMIUGYTVF J
AVH T
JVN  EDNB
JGRIKRUJDJ
JBB
BXUT
I RN ORWTKVUJIT
TUV NAWON
H ELEZ KOETHPA G
MRQDIHQB AOG
CLL  CJM  TOUKUNJJS
SZPTQP XP  T YNG
SZJ HX QTJEK
VZJ CFWKDKVXEEVDPK
DUDCFYTQDP W N
HU
YWART IOET
HBAJ QUO
CDZH XGZFQ
IGQFHAJ TQTLRJ IPI R
XQBQW VIIKJGTON
PB
XUEKVCKGCIPG
BHJY AYECZKV
QDYR RAAUVCA  ANDBHD
X
CJZFF SONVBXRKPSAGMX
BXCFRJA C WDQTIFH
T IEIST LRB GCTI
GJ  DUKGG PMGAXFATGS
CVRZRXU BT KLPNBZMI
MBT  TQE Q NDQW
GVUSLX A
KAIHEBSBW R V
RE  SSYKAMNXLJWE
C CCBDMCZMMOZH
TRQOTRSCCWEQ L
FXZRSUVA Q UH
B
GH P XKK  GYHUQMGL
Q
NIMWHY  RI ZHD
ANXTCVNJDVWJYO
KTDWLD
'''


if __name__ == "__main__":
    T = int(raw_input())
    for t in xrange(T):
        N = int(raw_input())
        min_this_str = ""
        list_str = list()
        max_len = 0
        for n in xrange(N):
            this_str = raw_input()
            if len(set(this_str)-set(' ')) > max_len:
                max_len = len(set(this_str)-set(' '))
                min_this_str = this_str
                list_str = list()
                list_str.append(min_this_str)
            elif len(set(this_str)-set(' ')) ==max_len:
                list_str.append(this_str)
                if this_str< min_this_str:
                    min_this_str =   this_str
            # print this_str, "min_this_str"min_this_str, max_len

        # if len(list_str)>1:
        #     print list_str, max_len
        print "Case #"+str(t+1)+": "+str(min_this_str)