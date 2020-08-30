#include <bits/stdc++.h>
using namespace std;

typedef struct task{
    int M, D, fin;
    bool done;
    task(int a, int b){D = a; M = b; done = false;}
}task;

vector<pair<int, task> > tasks;
vector<pair<int, task> > taskList;
vector<bool> incomplete;

int T, D, M;
int ttime = 1;

void display(){
    for(auto a : tasks)
        cout <<"Task: "<<a.first +1<<" => by "<< a.second.D << " requires "<<a.second.M <<" last: "<<a.second.fin<<" done: "<< a.second.done << endl;
    cout << endl;
}

struct sort_predicate{
    bool operator()(const pair<int, task> &p1, const pair<int, task> &p2){
            if (p1.second.D == p2.second.D)
                return p1.second.M < p2.second.M;
            return p1.second.D < p2.second.D;
    }
};

bool done(){
    for (auto a : tasks)
        if (!a.second.done)
            return false;
    return true;
}

int previousIncomplete(int pos){
    int inC = 0;
    for (int i = 0; i < pos; i++)
        if (incomplete[i] == true)
            inC += 1;
    return inC;
}

int main(){
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> D >> M;
        taskList.push_back(make_pair(i,task(D, M)));
    }

    for (int i = 4; i <= 4; i++){
        tasks.clear();
        ttime = 1;

        for (int j = 0; j < i; j++){
            tasks.push_back(taskList[j]);
        }
        incomplete.resize(4 , false);

        sort(tasks.begin(),tasks.end(),sort_predicate());

        while (!done()){
            cout <<"Now the time: "<<ttime<<endl;
            vector<pair<int, task> > :: iterator it = tasks.begin();

            while (it != tasks.end()){
                if(!it ->second.done){
                    if (it -> second.M + ttime < it -> second.D){
                        cout <<"Previous inc: "<<previousIncomplete(it -> first);
                        if (previousIncomplete(it -> first) != 0){
                            cout <<" Skipping: Task: "<<it->first+1<<endl;
                            it ++;
                            continue;
                        }
                        else {
                            it-> second.M -= 1;
                            it-> second.fin = ttime;
                            ttime += 1;
                        }
                    }
                    else{
                        it-> second.M -= 1;
                        it-> second.fin = ttime;
                        ttime += 1;
                    }
                }
                it++;
            }

            // Now consider only those who are left
            it = tasks.begin();
            while (it != tasks.end()){
                if (it->second.M == 0){
                    it->second.done = true;
                    incomplete[it -> first] = false;
                }
                it ++;
            }
            display();
        }

        int maximum = -1;
        for (auto a : tasks){
            if (a.second.D > a.second.fin)
                maximum = max(maximum, 0);
            else maximum = max(maximum, a.second.fin - a.second.D);
        }
        cout << maximum << endl;
    }

    return 0;
}
















//
