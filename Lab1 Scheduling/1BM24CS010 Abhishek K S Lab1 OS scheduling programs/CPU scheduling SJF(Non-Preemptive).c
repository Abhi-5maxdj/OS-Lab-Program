#include<stdio.h>
struct process{
    int id,at,bt,ct,tat,wt,rt;
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];
    for (int i = 0; i < n; i++){
        p[i].id = i + 1;
        printf("Enter Arrival Time for P%d: ", p[i].id);
        scanf("%d", &p[i].at);
        printf("Enter Burst Time for P%d: ", p[i].id);
        scanf("%d", &p[i].bt);
    }

    int completed=0,time=0,sumtat=0,sumwt=0;
    int iscompleted[n];
    for(int i=0;i<n;i++) iscompleted[i]=0;

    while(completed!=n){
        int index=-1;
        int minbt=1e9;
        for(int i=0;i<n;i++){
            if(p[i].at<=time && !iscompleted[i]){
                if(p[i].bt<minbt){
                    minbt=p[i].bt;
                    index=i;
                }
            }
        }
        if(index!=-1){
            p[index].ct=time+p[index].bt;
            p[index].tat=p[index].ct-p[index].at;
            p[index].wt=p[index].tat-p[index].bt;
            p[index].rt=p[index].wt;
            sumtat+=p[index].tat;
            sumwt+=p[index].wt;
            time=p[index].ct;
            iscompleted[index]=1;
            completed++;
        } else {
            time++;
        }
    }

    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }

    printf("\nAverage TAT: %.2f", (float)sumtat/n);
    printf("\nAverage WT: %.2f", (float)sumwt/n);
}
