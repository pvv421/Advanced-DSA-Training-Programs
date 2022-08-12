#include <bits/stdc++.h>
using namespace std;
int st[] = {10, 7, 5, 18, 12, 20, 15};
int numberOfElements = 7, sum = 30;
 
class SubSet{
public:
  stack<int> solutionSet;
  bool hasSolution;
  
  void solve(int s, int idx){
    if(s>sum)
        return;
    if(s==sum){
        hasSolution = true;
        displaySolutionSet();
        return;
    }
    for(int i=idx; i<numberOfElements; i++){
        solutionSet.push(st[i]);
        solve(s+st[i],i+1);        
        solutionSet.pop();
    }
  }
  void displaySolutionSet(){
        stack<int> temp;
      
        while (!solutionSet.empty()) 
        { 
            cout <<  solutionSet.top() << " "; 
            temp.push(solutionSet.top()); 
            solutionSet.pop();
        } 
        cout << '\n';
        while (!temp.empty()) 
        { 
            solutionSet.push(temp.top()); 
            temp.pop();
        } 
    }
};
void SumOfSub(int s[],int k, int r)
{
    
}
int main()
{
    SubSet ss;
    ss.solve(0,0);
	    
	if(ss.hasSolution == false)
	    cout << "No Solution";
 
    return 0;
}
