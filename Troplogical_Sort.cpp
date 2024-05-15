#include<bits/stdc++.h>

using namespace std;


struct vertex{
    char name;
    char color;
    int parent;
    int t;
    int f;
};
class graph{
    private:
        int a[10][10];
        int n;
        int p=0;
        int time=0;
        vertex *v;
        stack <vertex> s,temp;
    public:
        void getAdjMat(){
            cout<<"Enter The No Of Vertices:"<<endl;
            cin>>n;
            for(int i=0;i<n;i++){
                cout<<"Enter The Name of The Vertex["<<i+1<<"]"<<endl;
                cin>>v[i].name;
                v[i].color='w';
            }
            cout<<"Enter The Adjacency Matrix Elements of Order "<<n<<":"<<endl;
            for(int j=0;j<n;j++){
                for(int i=0;i<n;i++){
                    cin>>a[j][i];
                }
            }
            cout<<"Got The Adjacency Matrix"<<endl;
        }
        void DFS_visit(int u){
            v[u].t = ++time;
            v[u].color='g';
            for(int j=0;j<n;j++)
            {
                if(a[u][j]==1 && v[j].color=='w')
                {
                    v[j].parent=u;
                    DFS_visit(j);
                }
            }
            v[u].f= ++time;
            v[u].color='b';
            s.push(v[u]);
            return;
        }
        void DFS(char name)
        {
            int f=-1;
            for(int i=0;i<n;i++){
                if(v[i].name==name){
                f=i;
                break;
                }
            }
            if(f==-1){
                cout<<"Vertex Not Found"<<endl;
                return;
            }
            time =0;
            if(v[f].color=='w'){
                DFS_visit(f);
            }
            for (int i = 0; i < n; i++)
            {
                if(v[i].color=='w'){
                    DFS_visit(i);
                }
            }
            return;
        }
        void printTropoSort(){
            for(int i=0;i<n;i++){
                cout<<s.top().name<<"\t";
                temp.push(s.top());
                s.pop();
            }
            for(int i=0;i<n;i++){
                s.push(temp.top());
                temp.pop();
            }
            cout<<endl;
        }
};

int main(){
    graph ver;
    char name;
    ver.getAdjMat();
    cout<<"Enter The Name Of The Starting Vertex:"<<endl;
    cin>>name;
    ver.DFS(name);
    ver.printTropoSort();
    return 0;
}