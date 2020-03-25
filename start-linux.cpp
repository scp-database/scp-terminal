#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
int begi[8]={1,1000,2000,3000,4000,5000,1,1000},endd[8]={999,1999,2999,3999,4999,5999,999,1999};
string find_name(int id,bool cn){
  char s[101];
  if(cn){
    sprintf(s,"cat cn/name-cn-%d.txt",id);
  }
  else{
    sprintf(s,"cat cn/name-%d.txt",id);
  }
  return string(s);
}
string decode(int id,int cn){
  string v="cat cn/";
  string tmp=to_string(id);
  if(cn){
    v+="scp-cn-";
  }
  else{
    v+="scp-";
  }
  if(id<=999){
    while(tmp.length()!=3)tmp="0"+tmp;
  }
  v+=tmp;
  v+=".txt";
  return v;
}
void print_file(int be,int ed,bool cn){
  cout<<"当前目录下共有"<<ed-be+1<<"篇文章"<<endl;
  cout<<"正在输出名字..."<<endl;
  for(int i=be;i<=ed;i++){
    system(find_name(i,cn).c_str());
    cout<<endl;
  }
  cout<<"输出完成，请选择要查看的文档:("<<be<<"~"<<ed<<"):";
  int type;
  cin>>type;
  if(type<be||type>ed){
    puts("输入错误，请在3秒后重新选择...");
    sleep(3);
    return;
  }
  printf("\033c");
  cout<<"正在读取文档..."<<endl;
  sleep(2);
  system(decode(type,cn).c_str());
  cout<<"输入q退出:";
  char c;
  while(cin>>c){
    if(c=='q')return;
    cout<<"错误,输入q退出:";
  }
}
void sleep_print(string s,double tim){
  int l=s.length();
  for(int i=0;i<l;i++){
    sleep(tim);
    putchar(s[i]);
    fflush(stdout);
  }
}
void start_read(){
  cout<<"请选择要查看的文档系列:"<<endl;
  cout<<"1.scp-001~scp-999"<<endl;
  cout<<"2.scp-1000~scp-1999"<<endl;
  cout<<"3.scp-2000~scp-2999"<<endl;
  cout<<"4.scp-3000~scp-3999"<<endl;
  cout<<"5.scp-4000~scp-4999"<<endl;
  cout<<"6.scp-5000~scp-5999"<<endl;
  cout<<"7.scp-cn-001~scp-cn-999"<<endl;
  cout<<"8.scp-cn-1000~scp-cn-1999"<<endl;
  cout<<"请输入:(1~8):";
  int type;
  cin>>type;
  type--;
  if(type<=5){
    print_file(begi[type],endd[type],0);
  }
  else if(type<=7){
    print_file(begi[type],endd[type],1);
  }
  else{
    cout<<"输入错误，请在3秒后重新输入";
    sleep_print("..\n",1);
  }
  return;
}
void work(bool c=1){
  if(c)
  printf("\033c");
  cout<<"欢迎来到scp基金会数据库命令行版本，请选择需要使用的功能"<<endl;
  cout<<"1.查看文档"<<endl;
  cout<<"2.版本信息"<<endl;
  cout<<"3.退出"<<endl;
  cout<<"请输入(1/2/3):";
  int type;
  cin>>type;
  if(type==1){
    start_read();
    work();
  }
  else if(type==2){
    cout<<"--------------------------"<<endl;
    cout<<"|  scp基金会数据库 v1.2  |"<<endl;
    cout<<"|Developed by ZhangYiming|"<<endl;
    cout<<"--------------------------"<<endl;
    work(0);
  }
  else if(type==3){
    exit(0);
  }
  else{
    cout<<"输入错误，程序将在3秒后重启..."<<endl;
    sleep(3);
    work();
  }
}
int main(){
  printf("\033c");
  cout<<"<欢迎来到scp基金会数据库,请登录>"<<endl;
  cout<<"运行目录:";
  fflush(stdout);
  system("pwd");
  cout<<"用户名:O5-*"<<endl;
  cout<<"密码:";
  fflush(stdout);
  sleep_print("***",0);
  sleep(1);
  sleep_print("***",0);
  sleep(1);
  cout<<endl;
  cout<<"正在登陆";
  fflush(stdout);
  sleep_print("...",1);
  cout<<endl;
  cout<<"<登陆成功,三秒后自动进入主程序>"<<endl;
  if(access("cn/scp-001.txt",F_OK)!=0){
    puts("运行目录错误，请在下载后的目录中使用./运行，不要双击运行");
    puts("程序即将退出");
    sleep_print("3\n2\n1\n",1);
    return 0;
  }
  sleep_print("3\n2\n1\n",1);
  work();
  return 0;
}
