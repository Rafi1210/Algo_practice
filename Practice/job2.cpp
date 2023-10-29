#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id, loss, time;
};

bool compareJobs(const Job& a, const Job& b) {
    // Sort jobs based on the cost of delaying each job
    return (a.loss * b.time) > (b.loss * a.time);
}

vector<int> minimizeLossSequence(vector<int>& L, vector<int>& T) {
    int n = L.size();
    vector<Job> jobs(n);
    
    for (int i = 0; i < n; ++i) {
        jobs[i].id = i + 1;
        jobs[i].loss = L[i];
        jobs[i].time = T[i];
    }
    
    sort(jobs.begin(), jobs.end(), compareJobs);

    vector<int> sequence;
    for (const Job& job : jobs) {
        sequence.push_back(job.id);
    }

    return sequence;
}

int main() {
    vector<int> L = {1, 2, 3, 5, 6};
    vector<int> T = {2, 4, 1, 3, 2};

    vector<int> sequence = minimizeLossSequence(L, T);

    cout << "Job sequence to minimize overall loss: ";
    for (int job : sequence) {
        cout << job << " ";
    }
    cout << endl;

    return 0;
}
