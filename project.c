#include<stdio.h>
#include<math.h>
int st[10];
void fcfs(){
int bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0};
int n,sum=0;
float totalTAT=0,totalWT=0;
printf("Enter number of processes: ");
scanf("%d",&n);
printf("Enter Arrival time and Burst time for each process:\n");
for(int i=0;i<n;i++)
{
 printf("Arrival time of process[%d]: ",i+1);
 scanf("%d",&at[i]);
 printf("Burst time of process[%d]: ",i+1);
 scanf("%d",&bt[i]);
}
for(int j=0;j<n;j++)
{
 sum+=bt[j];
 ct[j]+=sum;
}
for(int k=0;k<n;k++)
{
 tat[k]=ct[k]-at[k];
 totalTAT+=tat[k];
}
for(int k=0;k<n;k++)
{
 wt[k]=tat[k]-bt[k];
 totalWT+=wt[k];
}
printf("P#\t AT\t BT\t CT\t TAT\t WT\t\n\n");
for(int i=0;i<n;i++)
{
 printf("P%d\t %d\t %d\t %d\t %d\t %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
}
printf("\nAverage Turnaround Time = %f\n",totalTAT/n);
printf("Average WT = %f\n\n",totalWT/n);
}
void sjf(){
int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
int bt[10],temp,j,at[10],wt[10],tt[10],ta=0,sum=0;
float wavg=0,tavg=0,tsum=0,wsum=0;
printf(" -------Shortest Job First Scheduling-------\n");
printf("\nEnter the No. of processes :");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\tEnter the burst time of %d process :",i+1);
scanf(" %d",&bt[i]);
printf("\tEnter the arrival time of %d process :",i+1);
scanf(" %d",&at[i]);
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(at[i]<at[j])
{
temp=p[j];
p[j]=p[i];
p[i]=temp;
temp=at[j];
at[j]=at[i];
at[i]=temp;
temp=bt[j];
bt[j]=bt[i];
bt[i]=temp;
}
}
}
for(j=0;j<n;j++)
{
btime=btime+bt[j];
min=bt[k];
for(i=k;i<n;i++)
{
if (btime>=at[i] && bt[i]<min)
{
temp=p[k];
p[k]=p[i];
p[i]=temp;
temp=at[k];
at[k]=at[i];
at[i]=temp;
temp=bt[k];
bt[k]=bt[i];
bt[i]=temp;
}
}
k++;
}
wt[0]=0;
for(i=1;i<n;i++)
{
sum=sum+bt[i-1];
wt[i]=sum-at[i];
wsum=wsum+wt[i];
}
wavg=(wsum/n);
for(i=0;i<n;i++)
{
ta=ta+bt[i];
tt[i]=ta-at[i];
tsum=tsum+tt[i];
}
tavg=(tsum/n);
printf("************************");
printf("\n RESULT:-");
printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
for(i=0;i<n;i++)
{
printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[i],bt[i],at[i],wt[i],tt[i]);
}
printf("\n\nAVERAGE WAITING TIME : %f",wavg);
printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
}
void rr(){
 int i, limit, total = 0, x, counter = 0, time_quantum;
 int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10],
temp[10];
 float average_wait_time, average_turnaround_time;
 printf("Enter Total Number of Processes: ");
 scanf("%d", &limit);
 x = limit;
 for(i = 0; i < limit; i++)
 {
 printf("\nEnter Arrival Time of Process[%d]: ",i+1);
 scanf("%d", &arrival_time[i]);
 printf("Enter Burst Time of Process[%d]: ",i+1);
 scanf("%d", &burst_time[i]);
 temp[i] = burst_time[i];
 }
 printf("Enter Time Quantum: ");
 scanf("%d", &time_quantum);
 printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
 for(total = 0, i = 0; x != 0;)
 {
 if(temp[i] <= time_quantum && temp[i] > 0)
 {
 total = total + temp[i];
 temp[i] = 0;
 counter = 1;
 }
 else if(temp[i] > 0)
 {
 temp[i] = temp[i] - time_quantum;
 total = total + time_quantum;
 }
 if(temp[i] == 0 && counter == 1)
 {
 x--;
 printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total -
arrival_time[i], total - arrival_time[i] - burst_time[i]);
 wait_time = wait_time + total - arrival_time[i] - burst_time[i];
 turnaround_time = turnaround_time + total - arrival_time[i];
 counter = 0;
 }
 if(i == limit - 1)
 {
 i = 0;
 }
 else if(arrival_time[i + 1] <= total)
 {
 i++;
 }
 else
 {
 i = 0;
 }
 }
 average_wait_time = wait_time * 1.0 / limit;
 average_turnaround_time = turnaround_time * 1.0 / limit;
 printf("\n\nAverage Waiting Time: %f", average_wait_time);
 printf("\nAvg Turnaround Time: %f\n", average_turnaround_time);
}
int get_tq(int b[],int s)
{
int i,j,maxbt,tmp,hbt,median;
float k,l,m;
for(i=0;i<s;i++)
{
for(j=i+1;j<s;j++){
if(b[i]>b[j])
{
tmp=b[i];
b[i]=b[j];
b[j]=tmp;
}
}
}
int pos[s];
int nonzero = 0;
for(int i=0;i<s;i++)
{
if(b[i]!=0){
pos[nonzero] = b[i];
nonzero++;
}
}
if(nonzero == 0)
return 0;
hbt=pos[nonzero-1];
median=pos[nonzero/2];
for(i=0;i<s;i++)
st[i]=b[i];
l=(float)hbt;
m=(float)median;
k=sqrt(l*m);return(ceil(k));
}
void innovative(){
int turn[100],wait[100],burst[100];
int bt[100],wt[100],tat[100],n,tq;
int i,count=0,swt=0,stat=0,temp,sq=0;
float awt=0.0,atat=0.0;
printf("Enter the no. of processes:");
scanf("%d",&n);
printf(" burst time for all sequences:");
for(i=0;i<n;i++){
scanf("%d",&bt[i]);
st[i]=bt[i];
}
int cc = 0;
int exitflag = 0;
while(1){
tq=get_tq(st,n);
printf("\ntime quantum is ceilceil((highestbt*median)) = %d\n",tq);
if(tq == 0)
printf("All the processes has been executed\n");
for(i=0,count=0;i<n;i++){
if(cc == 0){
burst[i] = st[i];
}
temp=tq;
if(st[i]==0){
count++;
continue;
}
else if(st[i]>tq){
int aq = sq;
st[i]=st[i]-tq;
sq=sq+temp;
printf("Procoess %d from %d to %d\n",i,aq,sq);
}
else if(st[i]>=0){
int aq = sq;
temp=st[i];
st[i]=0;
sq=sq+temp;
turn[i] = sq;
printf("Procoess %d from %d to %d\n",i,aq,sq);
}
}
cc++;
if(n==count){
break;
}
}
for(i=0;i<n;i++)
{
wait[i] = turn[i] - burst[i];
swt=swt+wait[i];
stat=stat+turn[i];
}
awt=(float)swt/n;
atat=(float)stat/n;
printf("\nprocesses :");
for(int i=0;i<n;i++)
printf("%d ",i);
printf("\nTurn Around time for all processes : ");
for(int i=0;i<n;i++)
printf("%d ",turn[i]);
printf("\nBurst time for all processes :");
for(int i=0;i<n;i++)
printf("%d ",burst[i]);
printf("\nWaiting time for all processes :");
 for(int i=0;i<n;i++)
printf("%d ",wait[i]);
printf("\nAvg waiting time is %f\n",awt);
printf("\nAvg turn around time is %f\n",atat);
}
int main()
{
 printf("Welcome to CPU Scheduling:\n\n");
 int c,choice; 
 printf("Choice\tAlgorithm used\n1\tFCFS Algorithm\n2\tSJF Algorithm\n3\tRound
robin\n4\tOur innovative algorithm\n");
 do
 {
 printf("Enter your choice from the above table: ");
 scanf("%d",&c);
 switch(c)
 {
 case 1:fcfs();break;
 case 2:sjf();break;
 case 3:rr();break;
 case 4:innovative();break;
 default: printf("Please enter choice from 1 to 4 only\n");break;
 }
 printf("\n\nEnter 1 to continue 0 to stop");
 scanf("%d",&choice);
 }while(choice==1);
 } 