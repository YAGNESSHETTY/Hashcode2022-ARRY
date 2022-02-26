// Yagn_Shetty //
// Chaddi_gang_leader //

#include <bits/stdc++.h>
using namespace std;
#define int int64_t
void read(vector<int> &a);
void read(vector<string> &a);
void read(vector<vector<int>> &a);
void read(vector<pair<int, int>> &a);
#define nline "\n" ;
#define str(n) to_string(n)
#define binary(n) std::bitset<32>(n).to_string()
#define all(arr) arr.begin(), arr.end()
#define fastIO1 ios_base::sync_with_stdio(false)
#define fastIO2 cin.tie(NULL)
#define asort(a) sort(a.begin(), a.end())
#define dsort(a) sort(a.begin(), a.end(), greater<int>())
#define cendl cout << endl
#define imax INT_MAX
#define imin INT_MIN
#define lmax LONG_MAX
#define lmin LONG_MIN
#define vll vector<int>
#define m(a) map<a, a>
#define pi 3.14159265358979323846264338327950288419716939937510582097494459230
#define mod 1000000007
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))
#define mod 1000000007
#define Google(t) cout << "Case #" << t << ": ";
#define maxn 200001
#define ff first
#define ss second


struct comp
{
    bool operator()(const pair<int, int> x, const pair<int, int> y) const
    {
        return x.ff >= y.ff;
    }
};

 
//1   vector<pair<string , pair<string,int>>>allskills ; 
vector<pair<string , vector<pair<string,int>>>>allskills ; 





vector<pair<string ,pair<int ,vector<pair<string ,int>>>>>project_req ; 
vector<pair<int ,pair<string ,vector<pair<string ,int>>>>>dupli ; 




void solve()
{
    int ans = 0 ;
    int contri , project ;
    cin>>contri >> project ; 
    for(int i= 0 ; i<contri ; i++){
        string name ;
        cin>>name ;
        int noskill ; 
        cin>>noskill ;
        // 3 
        vector<pair<string ,int>>val ;
        for(int j=0 ; j < noskill ; j++){
            string skill ;
            int lvl ;
            cin>>skill ;
            cin>>lvl ;
            //2  allskills.push_back({name, {skill , lvl}}) ;
            // 4 
            val.push_back({skill , lvl}) ;
        }

        // 5
        allskills.push_back({name, val}) ;

    }
    for(int i=0 ; i< project ; i++){
        string pro_name ;
        cin>>pro_name;
        int no_day , score , bb  ,no_roles ;
        cin>>no_day >> score >> bb >> no_roles ;
        vector<pair<string , int>>all ;
        for(int j = 0 ; j < no_roles ; j++){
            string req_name ;
            cin>>req_name ;
            int skill_lvl ;
            cin>>skill_lvl ;
            all.push_back({req_name , skill_lvl}) ;
        }
        // project_req.push_back({pro_name , {score , all }});
        dupli.push_back({score , {pro_name , all}}) ;
    }



    sort(all(dupli)) ;
    for(int r = project-1 ; r >= 0 ; r--){
        project_req.push_back({dupli[r].second.first , {dupli[r].first , dupli[r].second.second}}) ;
    }

    vector<pair<string , vector<string>>>final_ans ;

    for(int i=0 ; i< project ; i++){
        vector<string>poss ; 
        int possible = 0 ;
        vector<int>position ;
        vector<bool>b1(allskills.size() , 0) ;
        for(int j=0 ; j < project_req[i].second.second.size() ; j++){
            string requirement = project_req[i].second.second[j].first ;
            int skil_lvl = project_req[i].second.second[j].second ;
            for(int l1 = 0 ; l1 < allskills.size() ; l1++){
                bool v5 = true ;
                for(int l2 = 0 ; l2 < allskills[l1].second.size() ; l2++){
                    if( (requirement == allskills[l1].second[l2].first)  && (allskills[l1].second[l2].second >= skil_lvl) && (b1[l1]!=true)){
                        b1[l1] = true ;
                        poss.push_back(allskills[l1].first) ;
                        possible++ ;
                        position.push_back(l1) ;
                        v5 = false;
                        break  ;   
                    }
                }
                if(v5 == false){
                    break ;
                }
            }
        }

        if(possible == project_req[i].second.second.size()){
            final_ans.push_back({project_req[i].first , poss}) ;
        }
        else{
            for(int v3 = 0 ; v3 < position.size() ; v3++){
                b1[v3] = false ;
            }
            position.clear() ;
        }
    }


    cout << final_ans.size()<< endl ;
    for(auto ans1:final_ans){
        cout << ans1.first << endl;
        for(auto ans2:ans1.second){
            cout << ans2 << " " ;
        }
        cout << endl ;
    }


}

int32_t main(){  
    fastIO1;
    fastIO2;

    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin) ;
    freopen("output.txt" , "w" , stdout) ;
    #endif
    int t = 1;
    // cin >> t;   
    for (int tt = 1; tt <= t; tt++)
    {
        // Google(tt);
        solve();
    }
    return 0;
}

void read(vector<int> & a)
{
    for (int i = 0; i < a.size(); i++)
        cin >> a[i];
}
void read(vector<string> & a)
{
    for (int i = 0; i < a.size(); i++)
        cin >> a[i];
}
void read(vector<vector<int>> & a)
{
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a[i].size(); j++)
            cin >> a[i][j];
}
void read(vector<pair<int, int>> & a)
{
    for (int i = 0; i < a.size(); i++)
        cin >> a[i].first >> a[i].second;
}