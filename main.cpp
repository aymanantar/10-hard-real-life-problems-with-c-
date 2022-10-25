#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;
void fix_the_sentence ()
{
    string s , curr="" ;
    cin.clear(); cin.sync();
    getline(cin,s);
    s+=' ';
    int n = s.size();
    queue < string > arr ;
    for ( int i=0 ; i<n ; i++)
    {
        if (s[i]==' ')
        {
          if ( !curr.empty() )
          {
              arr.push(curr);
          }
          curr="";
        }
        else
        {
            curr+=towlower(s[i]);
        }
    }
    arr.front()[0] = towupper ( arr.front () [0] );
    while (!arr.empty())
    {
        if ( ( arr.front()[0] >= 'a' && arr.front()[0] <= 'z')   || ( arr.front()[0] >= '0' && arr.front()[0] <= '9' )  )
        {
            cout<<' '<<arr.front();
        }
        else
        {
            cout<<arr.front();
        }
        arr.pop();
    }
    cout<<endl;
}
void sex_equality_speech ()
{
    map <string ,string > mp;
    mp["he"]="he or she";
    mp["him"]="him or her";
    mp["his"]="his or her";
    mp["man"]="man or woman";
    mp ["a man"]="a man or a woman";
    mp["He"]="He or she";
    mp["Him"]="Him or her";
    mp["His"]="His or her";
    mp["Man"]="Man or woman";
    mp ["A man"]="A man or a woman";
    string s , curr="" ;
    cin.clear(); cin.sync();
    getline(cin,s);
    s+=' ';
    int n = s.size();
    queue < string > arr ;
    for ( int i=0 ; i<n ; i++)
    {
        if (s[i]==' ')
        {
          if ( !curr.empty() )
          {
              arr.push(curr);
          }
          curr="";
        }
        else if (( s[i] >='a' && s[i] <='z')   || ( s[i] >='0' && s[i] <='9' )||( s[i] >='A' && s[i] <='Z')   )
        {
            curr+=s[i];
        }
        else
        {
          if ( !curr.empty() ) {arr.push(curr);}
          curr="";
          curr+=s[i];
          arr.push(curr);
          curr="";
        }
    }
    arr.front()[0]=towupper(arr.front()[0]);
    cout<<(  ( mp[arr.front()]!="" ) ? mp[arr.front()] :  arr.front() );
    arr.pop();
    while (!arr.empty())
    {
        if ( (arr.front()[0] >='A' && arr.front()[0] <='Z')   || ( arr.front()[0] >='0' && arr.front()[0] <='9' )  || (arr.front()[0] >='a' && arr.front()[0] <='z'))
        {
              cout<<' '<<(  ( mp[arr.front()]!="" ) ? mp[arr.front()] :  arr.front() );
        }
        else
        {
              cout<<(  ( mp[arr.front()]!="" ) ? mp[arr.front()] :  arr.front() );
        }
        arr.pop();
    }
    cout<<endl;
}
void players_ranking_system ( )
{
priority_queue < pair <int , string >  , vector < pair <int , string > > , greater<> > List ;
pair <int , string > new_player ;
int choice ;
bool  f = true ;
    while ( f ){
        cout<<"chose your operation: \n 1-enter new player \n 2-display top-10 \n 3-maximum score for a player\n 4-exist \n";
        cin>>choice ;
        switch (choice)
        {
        case  1 :
            {
                cout<<"enter player name followed by the player score (space-saperated) \n";
                cin>>new_player.second>>new_player.first;
                if ( List.size()==10 )
                {
                    if (List.top().first <= new_player.first)
                    {
                        List.pop();
                        List.push(new_player);
                    }
                }
                else
                {
                    List.push(new_player);
                }
                cout<<"your query has been done, thank you\n";
                continue;
            }
        case  2 :
            {
                stack < pair <int , string > > print ;
                while (! List.empty())
                {
                    print.push(List.top());
                    List.pop();
                }
                while (! print.empty())
                {
                    List.push(print.top());
                    cout<<print.top().second<<' '<<print.top().first<<endl;
                    print.pop();
                }
                cout<<"your query has been done, thank you\n";
                continue;
            }
        case  3 :
            {
                int score =-1;
                cout<<"Enter the player name :\n";
                string name ;
                cin>>  name ;
                queue < pair <int , string> > dummy ;
                while ( !List.empty() )
                {
                    if (List.top().second == name )
                    {
                        score = List.top().first;
                    }
                    dummy.push(List.top());
                    List.pop();
                }
                while ( ! dummy.empty() )
                {
                    List.push(dummy.front());
                    dummy.pop();
                }
                if (score !=-1)
                {
                    cout<<"maximum score recorded for "<<name<<" was "<<score<<endl;
                }
                else
                {
                    cout<<"This player was not in the top-10 list\n";
                }
                cout<<"your query has been done, thank you\n";
                continue;
            }
        case  4 :
        {
            cout<<"good night\n";
            f = false ;
            break;
        }
        default :
            cout<<"wrong number was picked\n";
        }
    }
}
string to_binary (int n) {
    string ret = "";
    ret+=('0'+( (n%2)==1 ));
    n/=2;
    if (n==0)
    {
        return ret ;
    }
        return ret+to_binary(n);
}
void binaryPrint(int n)
{
    string ans=to_binary(n);
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
void numbers(string prefix, int k , int len )
{
    if (k<0){return ;}
    string suffix = to_binary(k);
    reverse(suffix.begin(),suffix.end());
    cout<<prefix;
    for (int i=(prefix.size()+suffix.size()) ; i<len ; i++)
    {
        cout<<'0';
    }
    cout<<suffix<<endl;
    numbers( prefix , k-1 , len );
}
struct dominoT {
int leftDots;
int rightDots;
};
stack <pair <int ,int > > domino_ans ;
vector < int > domino_eltern ;
void print_domino_chain(vector<dominoT> & arr, int idx )
{
    domino_ans.push({arr[idx].leftDots , arr[idx].rightDots});
    if (domino_eltern [idx] == -1 )
    {
        cout<<domino_ans.top().first<<'|'<<domino_ans.top().second;
        domino_ans.pop();
        while (!domino_ans.empty())
        {
            cout<<" - "<<domino_ans.top().first<<'|'<<domino_ans.top().second;
            domino_ans.pop();
        }
        cout<<endl;
        return ;
    }
    print_domino_chain(arr , domino_eltern[idx] );
}
int FormsDominoChain (vector<dominoT> & arr ,int eltern = -1 , int cnt=0 )
{
    if ( cnt == arr.size() )
    {
        return  eltern ;
    }
    for (int i=0 ; i<arr.size() ;i++)
    {
        if ( ( eltern == -1 )  || ( domino_eltern [i] == -2  && (  arr[ eltern ].rightDots == arr[i].leftDots ) ) )
        {
            domino_eltern [i] = eltern ;
            int ret = FormsDominoChain ( arr , i , (cnt+1) ) ;
            if (ret >=0 )
            {
                return ret ;
            }
            else
            {
                domino_eltern [i] = -2 ;
                continue;
            }
        }
    }
    return - 1 ;
}
void pattern(int n, int i,int cnt=1)
{
    if (cnt==2*n){return ;}
    if ( ((cnt)%2)== 1 )
    {
        cout<<setw(((i+cnt)/2)+1)<<setfill(' ')<<"*"<<endl;
    }
    else
    {
        cout<<setw( ( (i+cnt)/2 )-( __gcd(n,cnt)/2) )<<""<<setw( __gcd(n,cnt) )<<setfill('*')<<""<<endl;
    }
    return pattern(n,i,cnt+1);


}
bool bears(int n)
{
    if (n==42)
    {
        return true ;
    }
    if ( (n > 42) && ((n%2)==0) )
    {
        bool ret = bears(n/2);
        if (ret)
        {
            return true;
        }
    }
    if ( (n>42) && ( (n % 3 == 0 ) || ( n%4 ==  0 ) ) )
    {
        int calc =( n - (  ( n%10 ) * ( (n % 100) / 10 )  )  );
        if ( calc != n )
        {
            bool ret = bears( calc ) ;
            if (ret)
            {
                return true;
            }
        }
    }
    if ( (n>42) && ( n%5==0 ) )
    {
        bool ret = bears (n-42);
        if (ret)
        {
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------------------------
template <typename T > class smart_array
{
private :
    T* arr;
    int len;
public :
    smart_array ()
    {
        arr = new T [0];
        len = 0 ;
    }
    ~smart_array ()
    {
        delete [] arr;
    }
   void Push_back(T input)
    {

            T* temp = new T[len+1];
             for (int i = 0; i < len; i++) {
                temp[i] = arr[i];
            }
            temp [len]=input;
            delete[] arr;
            arr = temp;
            len = len+1;
    }
    int Size ()
    {
        return len ;
    }
    int & operator[](int k)
    {
        if ( k >= 0  && k < len )
        {
        return arr [k] ;
        }
        else
        {
            cout<<k<<"-th element does not exist in your array , as its current length is "<<len<<endl;
        }
    }
    void operator= (smart_array <T> input)
    {
         delete[] arr;
         arr = new T [input.len];
         for (int i=0 ; i<input.len ; i++)
         {
             arr[i] = input[i];
         }

    }

};
void char_compare(string f,string s)
{
    ifstream  aa , bb;
    f+=".txt";
    s+=".txt";
    aa.open(f);
    bb.open(s);
    int line =0;
    string a , b ;
    while (!aa.eof() || !bb.eof() )
    {
        a=""; b="";
        cin.clear(); cin.sync();
        getline(aa,a);
        getline(bb,b);
        line ++ ;
        if (a.size()!=b.size())
        {
        cout<<" in line number : "<<line<<", the first file said : '"<<a<<"'\n while the second said : '"<<b<<"'"<<endl;
        return ;
        }
        for (int i=0 ; i<a.size() ; i++)
        {
            if (a[i]!=b[i])
            {
                  cout<<" in line number : "<<line<<", the first file said : '"<<a<<"'\n while the second said : '"<<b<<"'"<<endl;
                  return ;
            }
        }
    }
    cout<<"identical\n";


}
void word_compare(string f,string s)
{
    ifstream  aa , bb;
    f+=".txt";
    s+=".txt";
    aa.open(f);
    bb.open(s);
    int line =0;
    string a , b ;
    while (!aa.eof() || !bb.eof() )
    {
        a=""; b="";
        cin.clear(); cin.sync();
        getline(aa,a);
        getline(bb,b);
        line ++ ;
        int i=0 , j=0 ;
        while ( i<a.size() || j<b.size()  )
        {
            string ta="" , tb="";
            while (i<a.size())
            {
                if (a[i]==' ')
                {
                    if (ta.size())
                    {
                       break;
                    }
                    else
                    {
                        i++;
                        continue;
                    }
                }
                ta+=a[i];
                i++;
            }
            while (j<b.size())
            {
                if (b[j]==' ')
                {
                    if (tb.size())
                    {
                       break;
                    }
                    else
                    {
                        j++;
                        continue;
                    }
                }
                tb+=b[j];
                j++;
            }
            if (ta!=tb)
            {
            cout<<" in line number : "<<line<<", the first file said : '"<<ta<<"'\n while the second said : '"<<tb<<"'"<<endl;
            return ;
            }

        }
   }
    cout<<"identical\n";
}
void phising( string message , int cho )
{
    map <string , int > risk ;
    risk ["Invoice"]=3;
    risk ["Inv"]= 2;
    risk ["Missing"]= 3;
    risk ["New"]= 3;
    risk ["Message"]= 3;
    risk ["from"]= 1;
    risk ["jamaika"]= 1;
    risk ["dollars"]= 1;
    risk ["giza"]= 1;
    risk ["syria"]= 2;
    risk ["pound"]= 1;
    risk ["stuck"]= 5;
    risk ["immediatly"]= 1;
    risk ["air"]= 2;
    risk ["plane"]= 1;
    risk ["ticket"]= 7;
    risk ["mony"]= 1;
    risk ["gun"]= 24;
    risk ["your"]= 1;
    risk ["help"]= 4;
    risk ["situation"]= 1;
    risk ["way"]= 1;
    risk ["son"]= 1;
    risk ["id"]= 18;
    risk ["password"]= 190;
    risk ["phone"]= 4;
    risk ["email"]= 1;
    risk ["us"]= 2;
    risk ["Request"]= 23;
    risk ["Action"]= 1;
    map < string , int > wordfrq ;
    long long Risk =0;
    string tst="";
    if ( cho ==1 )
    {
        message+=".txt";
        ofstream ss ;
        ss.open(message);
        while (cin>>tst)
        {
           wordfrq[tst]++;
           Risk+=risk[tst];
        }
        cout<<"this message has a total points of "<<Risk<<" of risky messages\n";
    }
    else
    {
      for (int i=0 ; i<message.size() ; i++)
      {
          if (message[i]==' ' || message[i]=='.')
          {
              wordfrq[tst]++;
              Risk+=risk[tst];
              tst="";
          }
          else
          {
              tst+=message[i];
          }
      }
      wordfrq[tst]++;
      Risk+=risk[tst];
      cout<<"this message has a total points of "<<Risk<<" of risky messages\n";
    }
    for ( auto el : wordfrq )
    {
            if (risk[el.first])
            {
                cout<<el.first<<" was mentioned "<<el.second<<" times \n";
            }
    }
    cout<<"note that more than 40 points makes your message really dangerous \n";
}
int main()
{

    int problem ;
    cin>> problem;
    switch (problem)
    {
    case 1 :
    {
        fix_the_sentence();
        break;
    }
    case 2 :
    {
        sex_equality_speech();
        break;
    }
    case 3 :
    {
        players_ranking_system();
        break;
    }
    case 4 :
    {
        cout<<"chose the operation\n 1-a \n 2-b \n";
        int c;
        cin>>c;
        switch (c)
        {
        case 1 :
            int num ;
            cout<<"Enter your number in decimal \n";
            cin >> num ;
            binaryPrint(num);
        case 2 :
            string str ;
            cout<<"Enter prefix string followed by the integer k (space-separated) :\n";
            cin>>str>>num;
            numbers (str ,  pow(2,num)-1  , str.size()+num);
        }
        break;
    }
    case 5 :
    {
        int size_of_domino ;
        cout<<"enter the number of domino peaces \n";
        cin>>size_of_domino ;
        vector < dominoT > arr (size_of_domino);
        cout<<"enter "<<size_of_domino<<" lines, representing the dominos.\n for each line enter left and right number written on the domino peace (space-separated) : \n";
        for (int i=0 ; i < size_of_domino ; i++)
        {
            cin>>arr[i].leftDots>>arr[i].rightDots;
        }
        domino_eltern.resize( size_of_domino , -2 );
        int returned_value = FormsDominoChain (arr) ;
        if ( returned_value >= 0  )
        {
            print_domino_chain(arr, returned_value );
        }
        else
        {
            cout<<"cannot form a domino chain with given data \n";
        }
        break;
    }
    case 6 :
    {
        int a , b ;
        cout<<"enter the two numbers  n , i ( space-separated )\n*note that n should be power of 2 greater than zero.\n";
        cin>>a>>b;
        pattern(a,b);
        break;
    }
    case 7 :
    {
        int n ;
        cout<<"enter the initial number of the bears :\n";
        cin>>n ;
        cout<<( bears( n ) ? "Yes, you can " : "No, you can't ")<<"get 42 bears with given values... \n";
        break;
    }
    case 8 :
    {
    //testing.................................
        smart_array <int> ae;
        cout<<ae.Size()<<endl;
        //cout<<ae[0]<<endl;
        ae.Push_back(2);
        ae.Push_back(1);
        ae.Push_back(2);
        ae.Push_back(2);
        smart_array < int > be=ae;
        be[3]=6;
        for (int i=0 ; i<be.Size() ; i++ )
        {
            cout<<be[i]<<' ';
        }
        cout<<endl;
        break;
    }
    case 9 :
    {
        cout<<"enter the names of two files (space-separated) :\n";
        string f , ff ;
        cin>>f>>ff;
        int co ;
        cout<<" for character comparison press 1 \n for word comparison press 2 : \n";
        cin>>co;
        if (co==1)
        {
            char_compare(f,ff);
        }
        else
        {
            word_compare(f,ff);
        }
        break;
    }
    case 10 :
    {
        cout<<" for scanning a file press 1\n for scanning a text press 2\n";
        int cho ;
        cin>>cho;
        switch (cho)
        {
            case 1:
            {
                cout<<"enter your file name \n";
                string message;
                cin>>message;
                phising(message,1);
                break ;
            }
           case 2:
            {
                cout<<"enter your message\n";
                string message;
                cin.clear(); cin.sync();
                getline(cin,message);
                phising(message,2);
                break;

            }
            default :
                cout<<"wrong number was chosen\n";
        }
        break ;
    }
    default :
        cout<<"wrong number was picked\n";
    }

    return 0;
}
+
