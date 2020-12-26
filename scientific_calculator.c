#include<math.h>
#include"iGraphics.h"
#include"gl.h"
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int i=0, j, k, a, b, x, y, p=0, in, l,mode=0;
int gbutton, gstate=1, gmx ,gmy, movex, movey, ind=0,tot=0,memory[3],modar=0;
char str[1000], res[1000], cop[1000],sstr[100],exam[100];
int mod=1;
#define pi 3.141592654
char sch[40];
char infix[200], post[30], stack[30], stg[100],sss[100];
int top=-1;
//shehab's variables
char ch[100],evaluate[100],hayre[100],stri[100],matha[100],uttor[100],syntax[15];
int flag,flag1,muri,gorom,vagshesh,tutut,jhamela,rad_deg,shesh,br_push;
void func(int);
void printbits(int n);
int dectobin(int dec)
{
    int bin=0;
    int u=0;
    while(dec!=0)
    {
        int mod=dec%2;
        bin+=mod*pow(10.0,u++);
        dec/=2;
    }
    printf("%d\n",bin);
    return bin;
}
void foo(char arr[],int in, int a,int b,int c)
{
    if(in==strlen(arr))
    {
        if(a==0&&b==0&&c==0)shesh=1;
        //else printf("Error at position %d",len+1);
        return;
    }
    if(arr[in]=='(')foo(arr,in+1,a+1,b,c);
    else if(arr[in]=='{')foo(arr,in+1,a,b+1,c);
    else if(arr[in]=='[')foo(arr,in+1,a,b,c+1);
    else if(arr[in]==')')
    {
        if(in==0)
        {
            printf("Error at position 1");
            return;
        }
        if(a>0&&(arr[in-1]=='('||arr[in-1]==')'||arr[in-1]=='}'||arr[in-1]==']'))foo(arr,in+1,a-1,b,c);
        else
        {
            printf("Error at position %d",in+1);
            return ;
        }
    }
    else if(arr[in]=='}')
    {
        if(in==0)
        {
            printf("Error at position 1");
            return;
        }
        if(b>0&&(arr[in-1]=='{'||arr[in-1]==')'||arr[in-1]=='}'||arr[in-1]==']'))foo(arr,in+1,a,b-1,c);
        else
        {
            printf("Error at position %d",in+1);
            return ;
        }
    }
    else if(arr[in]==']')
    {
        if(in==0)
        {
            printf("Error at position 1");
            return;
        }
        if(c>0&&(arr[in-1]=='['||arr[in-1]==')'||arr[in-1]=='}'||arr[in-1]==']'))foo(arr,in+1,a,b,c-1);
        else
        {
            printf("Error at position %d",in+1);
            return ;
        }
    }
}
void binarytodec(char ar[])
{
    int sum=0,i, j=0, k, l, num, a, b;
    char ch[100]={0}, ch1[100]={0}, stt[100]={0}, *p;
    strcpy(ch,ar);
    a=1;
    num=0;
    for(i=0;ch[i];i++){
        if(ch[i]=='1' || ch[i]=='0'){
            sum+=((ch[i]-'0'));
            sum*=2;
        }
        else{
            sum/=2;
            itoa(sum,stt,10);
            if(sum){
                strcat(ch1,stt);
                j+=strlen(stt);

            }
            ch1[j]=ch[i];
            j++;
            sum=0;
        }
    }
    sum/=2;
    itoa(sum,stt,10);
    if(sum){
        strcat(ch1,stt);
        j+=strlen(stt);

    }
    ch1[j]=ch[i];
    j++;
    sum=0;
    ch1[j]='\0';
    p=ch1;
    strcpy(sss,ch1);
    printf("%s\n",sss);
}
void octaltodec(char ar[])
{
    int sum=0,i, j=0, k, l, num, a, b;
    char ch[100]={0}, ch1[100]={0}, stt[100]={0}, *p;
    strcpy(ch,ar);
    a=1;
    num=0;
    a=strlen(ch);
    for(i=0;ch[i];i++){
        if(ch[i]>='0' && ch[i]<='7'){
            sum+=((ch[i]-'0'));
            sum*=8;
        }
        else{
            sum/=8;
            itoa(sum,stt,10);
            if(sum){
                strcat(ch1,stt);
                j+=strlen(stt);

            }
            ch1[j]=ch[i];
            j++;
            sum=0;
        }
    }
    sum/=8;
    itoa(sum,stt,10);
    if(sum){
        strcat(ch1,stt);
        j+=strlen(stt);

    }
    ch1[j]=ch[i];
    j++;
    sum=0;
    ch1[j]='\0';
    p=ch1;
    strcpy(sss,ch1);
}
void hexatodec(char ar[])
{
    int sum=0,i, j=0, k, l, num, a, b;
    char ch[100]={0}, ch1[100]={0}, stt[100]={0}, *p;
    strcpy(ch,ar);
    a=1;
    num=0;
    for(i=0;ch[i];i++){
        if(ch[i]>='0' && ch[i]<='9'){
			sum = sum * 16 + (ch[i]-'0');
        }
        else if(ch[i]>='A' && ch[i]<='F') {
			sum = sum * 16 + (ch[i]-'A' + 10);
        }
		else if (ch[i]>='a' && ch[i]<='f'){
			sum = sum * 16 + (ch[i]-'a' + 10);
        }
        else{
            itoa(sum,stt,10);
            if(sum){
                strcat(ch1,stt);
                j+=strlen(stt);

            }
            ch1[j]=ch[i];
            j++;
            sum=0;
        }
    }
    itoa(sum,stt,10);
    if(sum){
        strcat(ch1,stt);
        j+=strlen(stt);

    }
    ch1[j]=ch[i];
    j++;
    sum=0;
    ch1[j]='\0';
    p=ch1;
    strcpy(sss,ch1);
}

double expressionsifat(char *c,int koto)
{
    //cout<<c<<endl;
    int is=0;
    if(*c=='-'){is=1;c++;}
    char *v=NULL,*m=c;
    while(isdigit(*c)||*c=='.')
        c++;
    double ans=0;
    if(*c=='+'||*c=='-')
    {
        if(*c=='+'&&koto%2==0)
        {
            v=strtok(m,"+");
            m=c+1;
            if(is==0)ans=atof(v)+expressionsifat(c+1,koto);
            else ans=-atof(v)+expressionsifat(c+1,koto);
        }
        else if(*c=='-'&&koto%2==0)
        {
            v=strtok(m,"-");
            m=c+1;
            if(is==0)ans=atof(v)-expressionsifat(c+1,koto+1);
            else ans=-atof(v)-expressionsifat(c+1,koto+1);
        }
        else if(*c=='+'&&koto%2==1)
        {
            v=strtok(m,"+");
            m=c+1;
            if(is==0)ans=atof(v)-expressionsifat(c+1,koto+1);
            else ans=-atof(v)-expressionsifat(c+1,koto+1);
        }
        else if(*c=='-'&&koto%2==1)
        {
            v=strtok(m,"-");
            m=c+1;
            if(is==0)ans=atof(v)+expressionsifat(c+1,koto);
            else ans=-atof(v)+expressionsifat(c+1,koto);
        }
    }
    else if(*c=='*'||*c=='/')
    {
        int sun=0;
        if(*c=='/')sun=1;
        double bushra;
        if(is==0)bushra=atof(strtok(m,"*/"));
        else bushra=-atof(strtok(m,"*/"));
        //cout<<bushra<<"kopal"<<endl;
        while(1)
        {
            is=0;
            c++;
            if(*c=='-')
            {
                is=1;
                c++;
            }
            m=c;
            while(isdigit(*c)||*c=='.')
                c++;
            if(sun&&(*c=='*'||*c=='/'))
            {
                sun=0;
                if(*c=='/')
                    sun=1;
                if(is==0)bushra/=atof(strtok(m,"*/"));
                else bushra/=-atof(strtok(m,"*/"));
            }
            else if(sun)
            {
                sun=0;
                if(*c=='+')
                    sun=1;
                else if(*c=='-')sun=2;
                if(is==0)bushra/=atof(strtok(m,"+-"));
                else bushra/=-atof(strtok(m,"+-"));
                //cout<<bushra<<"le"<<endl;
                break;
            }
            else if(sun==0&&(*c=='*'||*c=='/'))
            {
                sun=0;
                if(*c=='/')
                    sun=1;
                if(is==0)bushra*=atof(strtok(m,"*/"));
                else bushra*=-atof(strtok(m,"*/"));
            }
            else
            {
                sun=0;
                if(*c=='+')
                    sun=1;
                else if(*c=='-')sun=2;
                if(is==0)bushra*=atof(strtok(m,"+-"));
                else bushra*=-atof(strtok(m,"*/"));
                break;
            }
        }
        ans=bushra;
        if(sun==1&&koto%2==0)
            ans+=expressionsifat(c+1,koto);
        else if(sun==1&&koto%2==1)
            ans-=expressionsifat(c+1,koto+1);
        else if(sun==2&&koto%2==0)
            ans-=expressionsifat(c+1,koto+1);
        else if(sun==2&&koto%2==1)
            ans+=expressionsifat(c+1,koto);
    }
    else if(*c==')'&&is==0)ans=atof(m);
    else if(*c==')'&&is)ans=-atof(m);
    //cout<<ans<<endl;

    return ans;
}

void shihab()
{
    int len,i, x;
    for(i=0;evaluate[i];i++) evaluate[i]='\0';
    //gets();
    //cout<<expression(ch,0)<<endl;
    strcpy(sch,sss);
    //printf("%s\n", sch);
    len=strlen(sch);
    if(sch[0]!='(')
    {
        sch[len]=')';
        //cout<<ch<<endl;
        evaluate[0]='(';
        strcat(evaluate,sch);
        //cout<<expression(evaluate,0);
    }
    else
    {
        int hihi=1;
        //int ln=strlen(ch);
        for(i=1;i<len;i++)
        {
            if(hihi==0) break;
            if(sch[i]=='(')hihi++;
            else if(sch[i]==')')hihi--;
        }
        if(i!=len)
        {
            sch[len]=')';
            evaluate[0]='(';
            strcat(evaluate,sch);
        }
        else strcpy(evaluate,sch);
    }
    len=strlen(evaluate);
    //printf("e%s\n",evaluate);
    //cout<<evaluate<<endl;
    char *ptr=NULL;
    for(i=len-1;i>-1;i--)
    {
        //cout<<"-_-"<<endl;
        memset(sstr,0,sizeof sstr);
        //cout<<"HIHI"<<endl;
        //cout<<"htha"<<endl;
        if(evaluate[i]=='(')
        {
            memset(matha,0,sizeof matha);
            //cout<<evaluate<<" uff"<<endl;
            int sun=0;
            //printf("%d eibar\n",i);
            double ans;
            int j,k;
            ptr=&evaluate[i];
            //strcpy(str,evaluate);
            while(1)
            {
                //cout<<"HIHI"<<endl;
                if(*ptr==')'||*ptr==0)break;
                ptr++;
            }
            //cout<<*ptr<<endl;
            if(*ptr==')')ptr++;
            //cout<<(int)*ptr<<"-_-"<<endl;

            strcpy(matha,evaluate);
            ans=expressionsifat(&matha[i+1],0);
            //cout<<evaluate<<" er"<<endl;
            if(i==0);

            else if(evaluate[i-1]=='^')
            {
                if(!isdigit(evaluate[i-2]));
                else
                {
                    char tutu[40];
                    int j,mama=0;
                    for(j=i-2;;j--)
                    {
                        if(!isdigit(evaluate[j]))break;
                        tutu[mama++]=evaluate[j];
                    }
                    tutu[mama]=0;
                    strrev(tutu);
                    i=j+1;

                }
            }
            for(j=0;j<i;j++)
                sstr[j]=evaluate[j];

            sprintf(hayre,"%lf",ans);

            for(k=0;k<strlen(hayre);k++)
                sstr[j++]=hayre[k];

            strcat(sstr,ptr);
            memset(evaluate,0,sizeof evaluate);
            strcpy(evaluate,sstr);
            i=strlen(evaluate);
            ptr=NULL;
        }
        //printf("-_-\n");
    }

    printf("%lf\n",atof(evaluate));
	tot=atof(evaluate);
    if(mod==1){
        sprintf(res,"%d", atoi(evaluate));

        memset(exam,0,sizeof exam);
    }
    else if(mod==3){
        memset(exam,0,sizeof exam);
        sprintf(res,"%o", atoi(evaluate));

    }
    else if(mod==2){
        sprintf(res,"%0x", atoi(evaluate));

        memset(exam,0,sizeof exam);
    }
    else if(mod==4){
        x=atoi(evaluate);
        if(x>=0)    {
            itoa(x,res,2);
            memset(exam,0,sizeof exam);
        }
        else printbits(x);
    }

    printf("aaa:%s\n", res);
}

void printbits(int n)
{
    unsigned int i=0, m;
    char eee[3]={0};
    m=1;
    m=m<<31;
    //printf("%d ", m);
    memset(exam,0,sizeof exam);
    for(;m>0;m>>=1){
        i++;
        if(m&n) sprintf(eee,"1");
        else sprintf(eee,"0");
        //if(i%4==0) printf(" ");
        strcat(exam,eee);
    }
    printf("\n");
}
void rightrotate(char ar[])
{
    unsigned int s,n;
    char rotate[100];
    n=atoi(ar);
    //if(l!=0) n=l;
    printf("n:%d %d\n",n, l);
    s=32;
    int m, a, b;
    m= ~((~0)<<1);
    //printbits(m);
    a = n&m;
    //printf("a:%d\n",a);
    n=n>>1;
    a=a<<(31);
    //printbits(n);
    //printbits(a);
    n=n|a;
    itoa(n,rotate,10);
    //printbits(n);
    if(mod==1) itoa(n,res,10);
    else if(mod==4) {
        printbits(n);
        //else itoa(n,res,2);
    }
    else if(mod==2) itoa(n,res,16);
    else if(mod==3) itoa(n,res,8);
    strcpy(sss,rotate);
    l=n;
}
void leftrotate(char ar[])
{
    unsigned int s,n;
    char rotate[100];
    n=atoi(ar);
    //if(l!=0) n=l;
    //printf("n:%d %d\n",n, l);
    s=32;
    unsigned int m, a, b;
    if(n<0){
        n=n<<1;
        printf("%d\n",n);
        n=n|1;
        printf("%d\n",n);
    }
    else{
    m= 0x80000000;
    printf("m:%d\n",m);
    a = n&m;
    printf("a:%d\n",a);
    //printf("a:%d\n",a);
    n=n<<1;
    a=a>>(s-1);
    //printbits(n);
    //printbits(a);
    n=n|a;
    }
    itoa(n,rotate,10);
    printf("nn:%d\n",n);
    //printbits(n);
    if(mod==1) itoa(n,res,10);
    else if(mod==4) {
        printbits(n);
        //else itoa(n,res,2);
    }
    else if(mod==2) itoa(n,res,16);
    else if(mod==3) itoa(n,res,8);
    strcpy(sss,rotate);
    l=n;
}

void rightshift(char ar[])
{
    unsigned int a, b, m=1;
    char shift[100];
    a=atoi(ar);
    a=a>>1;
    printf("a:%d\n", a);
    itoa(a,shift,10);
    if(mod==1) itoa(a,res,10);
    else if(mod==4) {
        printbits(a);
        //else itoa(a,res,2);
    }
    else if(mod==2) itoa(a,res,16);
    else if(mod==3) itoa(a,res,8);
    printf("%s\n",res);
    //iSetColor(0,0,0);
    //iText(75,520,res, GLUT_BITMAP_HELVETICA_18);
    strcpy(sss,shift);
}
void leftshift(char ar[])
{
    unsigned int a, b, m=1;
    char shift[100];
    a=atoi(ar);
    a=a<<1;
    printf("a:%d\n", a);
    itoa(a,shift,10);
    if(mod==1) itoa(a,res,10);
    else if(mod==4) {
        printbits(a);
        //else itoa(a,res,2);
    }
    else if(mod==2) itoa(a,res,16);
    else if(mod==3) itoa(a,res,8);
    printf("%s\n",res);
    //iSetColor(0,0,0);
    //iText(75,520,res, GLUT_BITMAP_HELVETICA_18);
    strcpy(sss,shift);
}
double fact(int a)
{
    if(a<=1)return 1;
    return a*fact(a-1);
}

double asinh(double x)
{
    return log(x + sqrt(x*x + 1));
}

double acosh(double x)
{
    return log(x + sqrt(x*x - 1));
}

double atanh(double x)
{
    return (log(1+x) - log(1-x))/2;
}

double expression(char *c,int koto)
{
    //cout<<c<<endl;
    int is=0;
    if(*c=='-'){is=1;c++;}
    char *v=NULL,*m=c;
    while(isdigit(*c)||*c=='.')
        c++;
    double ans=0;
    if(*c=='+'||*c=='-')
    {
        if(*c=='+'&&koto%2==0)
        {
            v=strtok(m,"+");
            m=c+1;
            if(is==0)ans=atof(v)+expression(c+1,koto);
            else ans=-atof(v)+expression(c+1,koto);
        }
        else if(*c=='-'&&koto%2==0)
        {
            v=strtok(m,"-");
            m=c+1;
            if(is==0)ans=atof(v)-expression(c+1,koto+1);
            else ans=-atof(v)-expression(c+1,koto+1);
        }
        else if(*c=='+'&&koto%2==1)
        {
            v=strtok(m,"+");
            m=c+1;
            if(is==0)ans=atof(v)-expression(c+1,koto+1);
            else ans=-atof(v)-expression(c+1,koto+1);
        }
        else if(*c=='-'&&koto%2==1)
        {
            v=strtok(m,"-");
            m=c+1;
            if(is==0)ans=atof(v)+expression(c+1,koto);
            else ans=-atof(v)+expression(c+1,koto);
        }
    }
    else if(*c=='*'||*c=='/')
    {
        int sun=0;
        if(*c=='/')sun=1;
        double bushra;
        if(is==0)bushra=atof(strtok(m,"*/"));
        else bushra=-atof(strtok(m,"*/"));
        //cout<<bushra<<"kopal"<<endl;
        while(1)
        {
            is=0;
            c++;
            if(*c=='-')
            {
                is=1;
                c++;
            }
            m=c;
            while(isdigit(*c)||*c=='.')
                c++;
            if(sun&&(*c=='*'||*c=='/'))
            {
                sun=0;
                if(*c=='/')
                    sun=1;
                if(is==0)bushra/=atof(strtok(m,"*/"));
                else bushra/=-atof(strtok(m,"*/"));
            }
            else if(sun)
            {
                sun=0;
                if(*c=='+')
                    sun=1;
                else if(*c=='-')sun=2;
                if(is==0)bushra/=atof(strtok(m,"+-"));
                else bushra/=-atof(strtok(m,"+-"));
                //cout<<bushra<<"le"<<endl;
                break;
            }
            else if(sun==0&&(*c=='*'||*c=='/'))
            {
                sun=0;
                if(*c=='/')
                    sun=1;
                if(is==0)bushra*=atof(strtok(m,"*/"));
                else bushra*=-atof(strtok(m,"*/"));
            }
            else
            {
                sun=0;
                if(*c=='+')
                    sun=1;
                else if(*c=='-')sun=2;
                if(is==0)bushra*=atof(strtok(m,"+-"));
                else bushra*=-atof(strtok(m,"*/"));
                break;
            }
        }
        ans=bushra;
        if(sun==1&&koto%2==0)
            ans+=expression(c+1,koto);
        else if(sun==1&&koto%2==1)
            ans-=expression(c+1,koto+1);
        else if(sun==2&&koto%2==0)
            ans-=expression(c+1,koto+1);
        else if(sun==2&&koto%2==1)
            ans+=expression(c+1,koto);
    }
    else if(*c==')'&&is==0)ans=atof(m);
    else if(*c==')'&&is)ans=-atof(m);
    //cout<<ans<<endl;
    return ans;
}
void iDraw()
{
    //int ajaira=0;
    iClear();
    iSetColor(0,0,0);
    if(rad_deg==0&&mode==1){iSetColor(0,0,0);iText(600,600,"Degree");}
    else if(mode==1){iSetColor(0,0,0);iText(600,600,"Radian");}
    if(mode==0)
    {
        iSetColor(255,255,255);
        iFilledRectangle(0,0,700,700);
        iShowBMP(00,00,"finalcover.bmp");
    }
    else {
        iShowBMP(0,0,"final2.bmp");
        iSetColor(0,0,0);
        iText(630,670,"BACK",GLUT_BITMAP_HELVETICA_18);
        iSetColor(255,255,255);//actual keys
        iFilledRectangle(50,50,600,450);

        iSetColor(200,210,210);
        iFilledRectangle(60,60,580,430);

        iSetColor(255,255,255);//display result
        iFilledRectangle(50,505,600,110);
        iSetColor(200,210,210);
        iFilledRectangle(60,510,580,90);
        if(mode==2){for(p=80;p<=450;p+=66){
            for(j=151;j<=600;j+=61){
                if(j==578 && (p==80 || p==146)) continue;
                iSetColor(200,190,190);
                iFilledRectangle(j,p,50,60);
            }
        }}
        else if(mode==1){
            for(p=80;p<=450;p+=66){
                for(j=80;j<=600;j+=61){
                    if(j==578 && (p==80 || p==146)) continue;
                    iSetColor(200,190,190);
                    iFilledRectangle(j,p,50,60);
                }
            }}
        iSetColor(200,190,190);
        if(mode==2)iFilledRectangle(578,80,50,125);
        else iFilledRectangle(578,80,40,125);
        //equal sign er jonno
        if(mode==2){for(p=80;p<=450;p+=95){
            iSetColor(200,190,190);//first 8 ta button er jonno ekdom left e
            iFilledRectangle(90,p,50, 80);
        }}
        if(mode==2){
            if(mod==1){
                iSetColor(0,0,0);
                iText(580,604,"Decimal");
            }
            else if(mod==2){
                iSetColor(0,0,0);
                iText(555,604,"Hexadecimal");
            }
            else if(mod==3){
                iSetColor(0,0,0);
                iText(580,604,"Octal");
            }
            else if(mod==4){
                iSetColor(0,0,0);
                iText(580,604,"Binary");
            }
            iSetColor(0,0,0);
            iText(100,395,"Bin" ,GLUT_BITMAP_HELVETICA_18);
            iText(100,315,"Oct",GLUT_BITMAP_HELVETICA_18 );
            iText(100,210,"Dec",GLUT_BITMAP_HELVETICA_18);
            iText(100,115,"Hex",GLUT_BITMAP_HELVETICA_18);}
        if(mode==1)
        {
            iSetColor(0,0,0);
			if(rad_deg==0)iText(555,604,"Degree");
			else iText(555,604,"Radian");
            iText(100-8,90+10,"Exp",GLUT_BITMAP_HELVETICA_18);
            if(gorom==0)iText(100-10,140+10+15,"tanh",GLUT_BITMAP_HELVETICA_18);
            else iText(100-15,140+10+15,"atanh",GLUT_BITMAP_HELVETICA_18);
            if(gorom==0)iText(100-12,195+10+15+10+5,"cosh",GLUT_BITMAP_HELVETICA_18);
            else iText(100-17,195+10+15+10+5,"acosh",GLUT_BITMAP_HELVETICA_18);
            if(gorom==0)iText(100-8,240+10+15+30+5,"sinh",GLUT_BITMAP_HELVETICA_18);
            else iText(100-13,240+10+15+30+5,"asinh",GLUT_BITMAP_HELVETICA_18);
            iText(100-8,295+10+15+38+8,"Inv",GLUT_BITMAP_HELVETICA_18);
            if(gbutton==0 && gstate==0 && gmx>=80 && gmx<=130 && gmy>=80 && gmy<=140 && mode==1)
            {
                iSetColor(0,100,250);
                iText(100-8,90+10,"Exp",GLUT_BITMAP_HELVETICA_18);
            }
            if(gbutton==0 && gstate==0 && gmx>=80 && gmx<=130 && gmy>=80+66 && gmy<=140+66 && mode==1)
            {
                iSetColor(0,100,250);
                if(gorom==0)iText(100-10,140+10+15,"tanh",GLUT_BITMAP_HELVETICA_18);
                else iText(100-15,140+10+15,"atanh",GLUT_BITMAP_HELVETICA_18);
            }
            if(gbutton==0 && gstate==0 && gmx>=80 && gmx<=130 && gmy>=80+66+66 && gmy<=140+66+66 && mode==1)
            {
                iSetColor(0,100,250);
                if(gorom==0)iText(100-12,195+10+15+10+5,"cosh",GLUT_BITMAP_HELVETICA_18);
                else iText(100-17,195+10+15+10+5,"acosh",GLUT_BITMAP_HELVETICA_18);
            }
            if(gbutton==0 && gstate==0 && gmx>=80 && gmx<=130 && gmy>=80+66+66*2 && gmy<=140+66+66*2 && mode==1)
            {
                iSetColor(0,100,250);
                if(gorom==0)iText(100-8,240+10+15+30+5,"sinh",GLUT_BITMAP_HELVETICA_18);
                else iText(100-13,240+10+15+30+5,"asinh",GLUT_BITMAP_HELVETICA_18);
            }
            if(gbutton==0 && gstate==0 && gmx>=80 && gmx<=130 && gmy>=80+66+66*3 && gmy<=140+66+66*3 && mode==1)
            {
                iSetColor(0,100,250);
                iText(100-8,295+10+15+38+8,"Inv",GLUT_BITMAP_HELVETICA_18);
            }
        }

        if(gbutton==0 && gstate==0 && gmx>=90 && gmx<=140 && gmy>=365 && gmy<=445 && mode ==2){
            iSetColor(0,100,250);
            iText(100,395,"Bin",GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=90 && gmx<=140 && gmy>=270 && gmy<=350 && mode ==2){
            iSetColor(0,100,250);
            iText(100,315,"Oct",GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=90 && gmx<=140 && gmy>=175 && gmy<=255 && mode ==2){
            iSetColor(0,100,250);
            iText(100,210,"Dec",GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=90 && gmx<=140 && gmy>=80 && gmy<=160 && mode ==2){
            iSetColor(0,100,250);
            iText(100,115,"Hex",GLUT_BITMAP_HELVETICA_18);

        }




        iSetColor(0,0,0);
        if(mode==2)iText(595,140,"=", GLUT_BITMAP_HELVETICA_18);
        else iText(595-5,140,"=", GLUT_BITMAP_HELVETICA_18);
        if(mode==2)iText(595,230,"1/x", GLUT_BITMAP_HELVETICA_18);
        else iText(595-10,230,"1/x", GLUT_BITMAP_HELVETICA_18);
        if(mode==2)iText(595,300,"%", GLUT_BITMAP_HELVETICA_18);
        else iText(595-5,300,"%", GLUT_BITMAP_HELVETICA_18);
        if(mode==2)iText(585,370,"sqrt", GLUT_BITMAP_HELVETICA_18);
        else iText(585-5,370,"sqrt", GLUT_BITMAP_HELVETICA_18);
        if(mode==2)iText(595,440,"M-", GLUT_BITMAP_HELVETICA_18);
        else if(gorom==0)iText(585,440,"pi", GLUT_BITMAP_HELVETICA_18);
        else if(gorom==1)iText(580,440,"2*pi", GLUT_BITMAP_HELVETICA_18);

        if(gbutton==0 && gstate==0 && gmx>=578 && gmx<=628 && gmy>=80 && gmy<=206){
            iSetColor(0,100,250);
            if(mode==2)iText(595,140,"=", GLUT_BITMAP_HELVETICA_18);
            else iText(595-5,140,"=", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=578 && gmx<=628 && gmy>=212 && gmy<=272 ){
            iSetColor(0,100,250);
            if(mode==2)iText(595,230,"1/x", GLUT_BITMAP_HELVETICA_18);
            else iText(595-10,230,"1/x", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=578 && gmx<=628 && gmy>=278 && gmy<=338){
            iSetColor(0,100,250);
            if(mode==2)iText(595,300,"%", GLUT_BITMAP_HELVETICA_18);
            else iText(595-5,300,"%", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=578 && gmx<=628 && gmy>=344 && gmy<=404){
            iSetColor(0,100,250);
            if(mode==2)iText(585,370,"sqrt", GLUT_BITMAP_HELVETICA_18);
            else iText(585-5,370,"sqrt", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=578 && gmx<=628 && gmy>=410 && gmy<=470){
            iSetColor(0,100,250);
            if(mode==2)iText(595,440,"M-", GLUT_BITMAP_HELVETICA_18);
            else if(gorom==0)iText(585,440,"pi", GLUT_BITMAP_HELVETICA_18);
            else if(gorom==1)iText(580,440,"2*pi", GLUT_BITMAP_HELVETICA_18);

        }

        iSetColor(0,0,0);
        if(mode==2){
            iText(160,100,"Not", GLUT_BITMAP_HELVETICA_18);
            iText(160,170,"Lsh", GLUT_BITMAP_HELVETICA_18);
            iText(160,240,"Or", GLUT_BITMAP_HELVETICA_18);
            iText(160,310,"RoL", GLUT_BITMAP_HELVETICA_18);
            iText(160,380,"(", GLUT_BITMAP_HELVETICA_18);

            if(gbutton==0 && gstate==0 && gmx>=151 && gmx<=201 && gmy>=80 && gmy<=140){
                iSetColor(0,100,250);
                iText(160,100,"Not", GLUT_BITMAP_HELVETICA_18);

            }
            else if(gbutton==0 && gstate==0 && gmx>=151 && gmx<=201 && gmy>=146 && gmy<=206 ){
                iSetColor(0,100,250);
                iText(160,170,"Lsh", GLUT_BITMAP_HELVETICA_18);

            }
            else if(gbutton==0 && gstate==0 && gmx>=151 && gmx<=201 && gmy>=212 && gmy<=272){
                iSetColor(0,100,250);
                iText(160,240,"Or", GLUT_BITMAP_HELVETICA_18);

            }
            else if(gbutton==0 && gstate==0 && gmx>=151 && gmx<=201 && gmy>=278 && gmy<=338){
                iSetColor(0,100,250);
                iText(160,310,"RoL", GLUT_BITMAP_HELVETICA_18);

            }
            else if(gbutton==0 && gstate==0 && gmx>=151 && gmx<=201 && gmy>=344 && gmy<=404){
                iSetColor(0,100,250);
                iText(160,380,"(", GLUT_BITMAP_HELVETICA_18);

            }
            iSetColor(0,0,0);
            iText(220,100,"And", GLUT_BITMAP_HELVETICA_18);
            iText(220,170,"Rsh", GLUT_BITMAP_HELVETICA_18);
            iText(220,240,"Xor", GLUT_BITMAP_HELVETICA_18);
            iText(220,310,"RoR", GLUT_BITMAP_HELVETICA_18);
            iText(220,380,")", GLUT_BITMAP_HELVETICA_18);
            iText(220,440,"Mod", GLUT_BITMAP_HELVETICA_18);

            if(gbutton==0 && gstate==0 && gmx>=212 && gmx<=262 && gmy>=80 && gmy<=140){
                iSetColor(0,100,250);
                iText(220,100,"And", GLUT_BITMAP_HELVETICA_18);

            }
            else if(gbutton==0 && gstate==0 && gmx>=212 && gmx<=262 && gmy>=146 && gmy<=206 ){
                iSetColor(0,100,250);
                iText(220,170,"Rsh", GLUT_BITMAP_HELVETICA_18);

            }
            else if(gbutton==0 && gstate==0 && gmx>=212 && gmx<=262 && gmy>=212 && gmy<=272){
                iSetColor(0,100,250);
                iText(220,240,"Xor", GLUT_BITMAP_HELVETICA_18);

            }
            else if(gbutton==0 && gstate==0 && gmx>=212 && gmx<=262 && gmy>=278 && gmy<=338){
                iSetColor(0,100,250);
                iText(220,310,"RoR", GLUT_BITMAP_HELVETICA_18);

            }
            else if(gbutton==0 && gstate==0 && gmx>=212 && gmx<=262 && gmy>=344 && gmy<=404){
                iSetColor(0,100,250);
                iText(220,380,")", GLUT_BITMAP_HELVETICA_18);

            }
            else if(gbutton==0 && gstate==0 && gmx>=212 && gmx<=262 && gmy>=410 && gmy<=470){
                iSetColor(0,100,250);
                iText(220,440,"Mod", GLUT_BITMAP_HELVETICA_18);

            }

            iSetColor(0,0,0);
            iText(280,100,"F", GLUT_BITMAP_HELVETICA_18);
            iText(280,170,"E", GLUT_BITMAP_HELVETICA_18);
            iText(280,240,"D", GLUT_BITMAP_HELVETICA_18);
            iText(280,310,"C", GLUT_BITMAP_HELVETICA_18);
            iText(280,380,"B", GLUT_BITMAP_HELVETICA_18);
            iText(280,440,"A", GLUT_BITMAP_HELVETICA_18);

            if(gbutton==0 && gstate==0 && gmx>=273 && gmx<=323 && gmy>=80 && gmy<=140){
                iSetColor(0,100,250);
                iText(280,100,"F", GLUT_BITMAP_HELVETICA_18);

            }
            else if(gbutton==0 && gstate==0 && gmx>=273 && gmx<=323 && gmy>=146 && gmy<=206 ){
                iSetColor(0,100,250);
                iText(280,170,"E", GLUT_BITMAP_HELVETICA_18);


            }
            else if(gbutton==0 && gstate==0 && gmx>=273 && gmx<=323 && gmy>=212 && gmy<=272){
                iSetColor(0,100,250);
                iText(280,240,"D", GLUT_BITMAP_HELVETICA_18);


            }
            else if(gbutton==0 && gstate==0 && gmx>=273 && gmx<=323 && gmy>=278 && gmy<=338){
                iSetColor(0,100,250);
                iText(280,310,"C", GLUT_BITMAP_HELVETICA_18);

            }
            else if(gbutton==0 && gstate==0 && gmx>=273 && gmx<=323 && gmy>=344 && gmy<=404){
                iSetColor(0,100,250);
                iText(280,380,"B", GLUT_BITMAP_HELVETICA_18);

            }
            else if(gbutton==0 && gstate==0 && gmx>=273 && gmx<=323 && gmy>=410 && gmy<=470){
                iSetColor(0,100,250);
                iText(280,440,"A", GLUT_BITMAP_HELVETICA_18);

            }}

        else
        {
            iText(160-8,100,"Mod", GLUT_BITMAP_HELVETICA_18);
            if(gorom==0)iText(160-4,170,"tan", GLUT_BITMAP_HELVETICA_18);
            else iText(160-7,170,"atan", GLUT_BITMAP_HELVETICA_18);
            if(gorom==0)iText(160-4,240,"cos", GLUT_BITMAP_HELVETICA_18);
            else iText(160-8,240,"acos", GLUT_BITMAP_HELVETICA_18);
            if(gorom==0)iText(160,310-5,"sin", GLUT_BITMAP_HELVETICA_18);
            else iText(160-4,310-5,"asin", GLUT_BITMAP_HELVETICA_18);
            iText(160,380-10,"ln", GLUT_BITMAP_HELVETICA_18);

            if(gbutton==0 && gstate==0 && gmx>=151 && gmx<=201 && gmy>=80 && gmy<=140){
                iSetColor(0,100,250);
                iText(160-8,100,"Mod", GLUT_BITMAP_HELVETICA_18);

            }
            else if(gbutton==0 && gstate==0 && gmx>=151 && gmx<=201 && gmy>=146 && gmy<=206 ){
                iSetColor(0,100,250);
                if(gorom==0)iText(160-4,170,"tan", GLUT_BITMAP_HELVETICA_18);
                else iText(160-7,170,"atan", GLUT_BITMAP_HELVETICA_18);
            }
            else if(gbutton==0 && gstate==0 && gmx>=151 && gmx<=201 && gmy>=212 && gmy<=272){
                iSetColor(0,100,250);
                if(gorom==0)iText(160-4,240,"cos", GLUT_BITMAP_HELVETICA_18);
                else iText(160-8,240,"acos", GLUT_BITMAP_HELVETICA_18);
            }
            else if(gbutton==0 && gstate==0 && gmx>=151 && gmx<=201 && gmy>=278 && gmy<=338){
                iSetColor(0,100,250);
                if(gorom==0)iText(160,310-5,"sin", GLUT_BITMAP_HELVETICA_18);
                else iText(160-4,310-5,"asin", GLUT_BITMAP_HELVETICA_18);
            }
            else if(gbutton==0 && gstate==0 && gmx>=151 && gmx<=201 && gmy>=344 && gmy<=404){
                iSetColor(0,100,250);
                iText(160,380-10,"ln", GLUT_BITMAP_HELVETICA_18);

            }
            iSetColor(0,0,0);
            iText(220-5,100+5,"log", GLUT_BITMAP_HELVETICA_18);
            iText(220,170,"x", GLUT_BITMAP_HELVETICA_18);
            iText(225+3,175,"3", GLUT_BITMAP_HELVETICA_18);
            iText(220,240,"x", GLUT_BITMAP_HELVETICA_18);
            iText(225+3,245+3,"y", GLUT_BITMAP_HELVETICA_18);
            iText(220,310-10,"x", GLUT_BITMAP_HELVETICA_18);
            iText(225+3,315-10,"2", GLUT_BITMAP_HELVETICA_18);
            iText(220,380-5,"(", GLUT_BITMAP_HELVETICA_18);
            //iText(220,440,"Mod", GLUT_BITMAP_HELVETICA_18);

            if(gbutton==0 && gstate==0 && gmx>=212 && gmx<=262 && gmy>=80 && gmy<=140){
                iSetColor(0,100,250);
                iText(220-5,100+5,"log", GLUT_BITMAP_HELVETICA_18);

            }
            else if(gbutton==0 && gstate==0 && gmx>=212 && gmx<=262 && gmy>=146 && gmy<=206 ){
                iSetColor(0,100,250);
                iText(220,170,"x", GLUT_BITMAP_HELVETICA_18);
                iText(225+3,175,"3", GLUT_BITMAP_HELVETICA_18);

            }
            else if(gbutton==0 && gstate==0 && gmx>=212 && gmx<=262 && gmy>=212 && gmy<=272){
                iSetColor(0,100,250);
                iText(220,240,"x", GLUT_BITMAP_HELVETICA_18);
                iText(225+3,245+3,"y", GLUT_BITMAP_HELVETICA_18);

            }
            else if(gbutton==0 && gstate==0 && gmx>=212 && gmx<=262 && gmy>=278 && gmy<=338){
                iSetColor(0,100,250);
                iText(220,310-10,"x", GLUT_BITMAP_HELVETICA_18);
                iText(225+3,315-10,"2", GLUT_BITMAP_HELVETICA_18);

            }
            else if(gbutton==0 && gstate==0 && gmx>=212 && gmx<=262 && gmy>=344 && gmy<=404){
                iSetColor(0,100,250);
                iText(220,380-5,"(", GLUT_BITMAP_HELVETICA_18);

            }
            /*else if(gbutton==0 && gstate==0 && gmx>=212 && gmx<=262 && gmy>=410 && gmy<=470){
            iSetColor(0,100,250);
            iText(220,440,"Mod", GLUT_BITMAP_HELVETICA_18);

            }*/

            iSetColor(0,0,0);
            iText(280-5,100,"10", GLUT_BITMAP_HELVETICA_18);
            iText(295,110,"x", GLUT_BITMAP_HELVETICA_18);
            iText(280+5,170,"x", GLUT_BITMAP_HELVETICA_18);
            iText(270,178,"3", GLUT_BITMAP_HELVETICA_18);
            iLine(270,174,278,168);
            iLine(283,185,278,168);
            iText(280+5,240-4,"x", GLUT_BITMAP_HELVETICA_18);
            iText(270+5,248-4,"y", GLUT_BITMAP_HELVETICA_18);
            iLine(270+5,244-4,278+3,238-5);
            iLine(283+5,255-4,278+3,238-5);
            iText(280,310-5,"n!", GLUT_BITMAP_HELVETICA_18);
            iText(280+5,380-5,")", GLUT_BITMAP_HELVETICA_18);
            //iText(280,440,"A", GLUT_BITMAP_HELVETICA_18);

            if(gbutton==0 && gstate==0 && gmx>=273 && gmx<=323 && gmy>=80 && gmy<=140){
                iSetColor(0,100,250);
                iText(280-5,100,"10", GLUT_BITMAP_HELVETICA_18);
                iText(295,110,"x", GLUT_BITMAP_HELVETICA_18);
                //iLine(270,174,278,168);
                //iLine(283,185,278,168);

            }
            else if(gbutton==0 && gstate==0 && gmx>=273 && gmx<=323 && gmy>=146 && gmy<=206 ){
                iSetColor(0,100,250);
                iText(280+5,170,"x", GLUT_BITMAP_HELVETICA_18);
                iText(270,178,"3", GLUT_BITMAP_HELVETICA_18);
                iLine(270,174,278,168);
                iLine(283,185,278,168);

            }
            else if(gbutton==0 && gstate==0 && gmx>=273 && gmx<=323 && gmy>=212 && gmy<=272){
                iSetColor(0,100,250);
                iText(280+5,240-4,"x", GLUT_BITMAP_HELVETICA_18);
                iText(270+5,248-4,"y", GLUT_BITMAP_HELVETICA_18);
                iLine(270+5,244-4,278+3,238-5);
                iLine(283+5,255-4,278+3,238-5);


            }
            else if(gbutton==0 && gstate==0 && gmx>=273 && gmx<=323 && gmy>=278 && gmy<=338){
                iSetColor(0,100,250);
                iText(280,310-5,"n!", GLUT_BITMAP_HELVETICA_18);

            }
            else if(gbutton==0 && gstate==0 && gmx>=273 && gmx<=323 && gmy>=344 && gmy<=404){
                iSetColor(0,100,250);
                iText(280+5,380-5,")", GLUT_BITMAP_HELVETICA_18);

            }
            /*else if(gbutton==0 && gstate==0 && gmx>=273 && gmx<=323 && gmy>=410 && gmy<=470){
            iSetColor(0,100,250);
            iText(280,440,"A", GLUT_BITMAP_HELVETICA_18);

            }*/
        }

        iSetColor(0,0,0);
        iText(342,100,"0", GLUT_BITMAP_HELVETICA_18);
        iText(342,170,"1", GLUT_BITMAP_HELVETICA_18);
        iText(342,240,"4", GLUT_BITMAP_HELVETICA_18);
        iText(342,310,"7", GLUT_BITMAP_HELVETICA_18);
        iText(342-5,380-10,"<--", GLUT_BITMAP_HELVETICA_18);
        if(mode==2)iText(342,440,"MC", GLUT_BITMAP_HELVETICA_18);
        else iText(338,440-4,"e^x", GLUT_BITMAP_HELVETICA_18);

        if(gbutton==0 && gstate==0 && gmx>=334 && gmx<=384 && gmy>=80 && gmy<=140){
            iSetColor(0,100,250);
            iText(342,100,"0", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=334 && gmx<=384 && gmy>=146 && gmy<=206 ){
            iSetColor(0,100,250);
            iText(342,170,"1", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=334 && gmx<=384 && gmy>=212 && gmy<=272){
            iSetColor(0,100,250);
            iText(342,240,"4", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=334 && gmx<=384 && gmy>=278 && gmy<=338){
            iSetColor(0,100,250);
            iText(342,310,"7", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=334 && gmx<=384 && gmy>=344 && gmy<=404){
            iSetColor(0,100,250);
            iText(342-5,380-10,"<--", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=334 && gmx<=384 && gmy>=410 && gmy<=470){
            iSetColor(0,100,250);
            if(mode==2)iText(342,440,"MC", GLUT_BITMAP_HELVETICA_18);
            else iText(342-4,440-4,"e^x", GLUT_BITMAP_HELVETICA_18);

        }

        iSetColor(0,0,0);
        //iText(405,100,"0", GLUT_BITMAP_HELVETICA_18);
        iText(405,170,"2", GLUT_BITMAP_HELVETICA_18);
        iText(405,240,"5", GLUT_BITMAP_HELVETICA_18);
        iText(405,310,"8", GLUT_BITMAP_HELVETICA_18);
        iText(405-3,380-10,"CE", GLUT_BITMAP_HELVETICA_18);
        if(mode==2)iText(405,440,"MR", GLUT_BITMAP_HELVETICA_18);
        else if(gorom==0)iText(405-4,440-5,"Int", GLUT_BITMAP_HELVETICA_18);
        else if(gorom==1)iText(405-4,440-5,"frac", GLUT_BITMAP_HELVETICA_18);

        if(gbutton==0 && gstate==0 && gmx>=395 && gmx<=445 && gmy>=146 && gmy<=206 ){
            iSetColor(0,100,250);
            iText(405,170,"2", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=395 && gmx<=445 && gmy>=212 && gmy<=272){
            iSetColor(0,100,250);
            iText(405,240,"5", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=395 && gmx<=445 && gmy>=278 && gmy<=338){
            iSetColor(0,100,250);
            iText(405,310,"8", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=395 && gmx<=445 && gmy>=344 && gmy<=404){
            iSetColor(0,100,250);
            iText(405-3,380-10,"CE", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=395 && gmx<=445 && gmy>=410 && gmy<=470){
            iSetColor(0,100,250);
            if(mode==2)iText(405,440,"MR", GLUT_BITMAP_HELVETICA_18);
            else if(gorom==0)iText(405-4,440-5,"Int", GLUT_BITMAP_HELVETICA_18);
            else if(gorom==1)iText(405-4,440-5,"frac", GLUT_BITMAP_HELVETICA_18);

        }


        iSetColor(0,0,0);
        iFilledCircle(473,108,3);
        iText(465,170,"3", GLUT_BITMAP_HELVETICA_18);
        iText(465,240,"6", GLUT_BITMAP_HELVETICA_18);
        iText(465,310,"9", GLUT_BITMAP_HELVETICA_18);
        iText(465,380-10,"C", GLUT_BITMAP_HELVETICA_18);
        if(mode==2)iText(465,440,"MS", GLUT_BITMAP_HELVETICA_18);
        else iText(455,440-4,"Deg", GLUT_BITMAP_HELVETICA_18);

        if(gbutton==0 && gstate==0 && gmx>=456 && gmx<=506 && gmy>=80 && gmy<=140){
            iSetColor(0,100,250);
            iFilledCircle(473,108,3);

        }
        else if(gbutton==0 && gstate==0 && gmx>=456 && gmx<=506 && gmy>=146 && gmy<=206 ){
            iSetColor(0,100,250);
            iText(465,170,"3", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=456 && gmx<=506 && gmy>=212 && gmy<=272){
            iSetColor(0,100,250);
            iText(465,240,"6", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=456 && gmx<=506 && gmy>=278 && gmy<=338){
            iSetColor(0,100,250);
            iText(465,310,"9", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=456 && gmx<=506 && gmy>=344 && gmy<=404){
            iSetColor(0,100,250);
            iText(465,380-10,"C", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=456 && gmx<=506 && gmy>=410 && gmy<=470){
            iSetColor(0,100,250);
            if(mode==2)iText(465,440,"MS", GLUT_BITMAP_HELVETICA_18);
            else iText(455,440-4,"Deg", GLUT_BITMAP_HELVETICA_18);
        }

        iSetColor(0,0,0);
        iText(528,100,"+", GLUT_BITMAP_HELVETICA_18);
        iText(528,170,"-", GLUT_BITMAP_HELVETICA_18);
        iText(528,240,"*", GLUT_BITMAP_HELVETICA_18);
        iText(528,310,"/", GLUT_BITMAP_HELVETICA_18);
        if(mode==1)iText(524,375,"+-", GLUT_BITMAP_HELVETICA_18);
        else iText(524-10,375,"+-", GLUT_BITMAP_HELVETICA_18);
        if(mode==2)iText(528,440,"M+", GLUT_BITMAP_HELVETICA_18);
        else if(mode==1)iText(528-15,440-4,"Rad", GLUT_BITMAP_HELVETICA_18);

        if(gbutton==0 && gstate==0 && gmx>=517 && gmx<=567 && gmy>=80 && gmy<=140){
            iSetColor(0,100,250);
            iText(528,100,"+", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=517 && gmx<=567 && gmy>=146 && gmy<=206 ){
            iSetColor(0,100,250);
            iText(528,170,"-", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=517 && gmx<=567 && gmy>=212 && gmy<=272){
            iSetColor(0,100,250);
            iText(528,240,"*", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=517 && gmx<=567 && gmy>=278 && gmy<=338){
            iSetColor(0,100,250);
            iText(528,310,"/", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=517 && gmx<=567 && gmy>=344 && gmy<=404){
            iSetColor(0,100,250);
            if(mode==1)iText(530,375,"+-", GLUT_BITMAP_HELVETICA_18);
            else iText(544,375,"+-", GLUT_BITMAP_HELVETICA_18);

        }
        else if(gbutton==0 && gstate==0 && gmx>=517 && gmx<=567 && gmy>=410 && gmy<=470){
            iSetColor(0,100,250);
            if(mode==2)iText(528,440,"M+", GLUT_BITMAP_HELVETICA_18);
            else if(mode==1)iText(528-15,440-4,"Rad", GLUT_BITMAP_HELVETICA_18);
        }



        iSetColor(0,0,0);
        if(mode==2)iText(70,570,str,GLUT_BITMAP_HELVETICA_18);
        if(res[0]!='\0' && mode==2 && exam[0]=='\0') {
            iText(75,520,res, GLUT_BITMAP_HELVETICA_18);

            //printf("tot:%d\n", tot);

        }
        if(mode==2 && exam[0]!='\0') iText(75,520,exam, GLUT_BITMAP_HELVETICA_18);
        if(memory[0]!=0 && mode==2) {
            iSetColor(0,0,0);
            iText(615,520,"M", GLUT_BITMAP_HELVETICA_18);
        }}
    if(mode==1)iText(70,570,ch,GLUT_BITMAP_HELVETICA_18);
    if(mode==1)iText(75,520,uttor, GLUT_BITMAP_HELVETICA_18);
}
void func(int x)
{
    itoa(x,res,2);
}
void binpaste(char st[], int i)
{
    int j, k, l, a;
    a=i;
    l=strlen(st);//i hocche jeikhan theke g start hoe and sheikhane value gula just shift kora start hobe
    // printf("lst: %d\n", l);
    for(;i<l;i++){
        if(st[i]!='g') break;
    }
    for(i;i<l;i++){
        st[a]=st[i];
        a++;
    }
    st[a]='\0';

}

void binashol(char *st, char *end, int hold, int holde)
{
    int i, j, k=1, sand=0, sor=0, sxor=0, smod=0, aray[100]={0}, num1, num2, a, ans=0, cc=1, b, l;
    int mn=0;
    char chai[100]={0}, dhur[100], flag[100]={0}, strr[100]={0};
    i=0;
    for(;st!=end;st++){
        chai[i]=*st;
        // printf("s:%c", chai[i]);
        i++;
    }
    chai[i]= *st;
    chai[++i]='\0';
    // printf("chai:%s\n", chai);
    strcpy(dhur , chai);
    for(i=0;chai[i];i++){
        if(chai[i]=='%') smod++;
        else if(chai[i]=='&') sand++;
        else if(chai[i]=='|') sor++;
        else if(chai[i]=='^') sxor++;
    }
    // printf("and %d\n", sand);
    while(k)
    {
        k=0;
        if(sand||sor||smod||sxor) k=1;
        else break;
        for(i=0;chai[i];i++){
            if((chai[i]=='%' && smod) && flag[i]==0){
                //chai[i]='g';
                flag[i]=cc;
                stg[hold+i+1]='g';
                num2=0;
                if(flag[i+1]==0){
                    for(j=i+1;chai[j]!='&' && chai[j]!='|' && chai[j]!='^' && chai[j]!='%' && j<holde-1-hold;j++){
                        num2+=((chai[j]-'0'));
                        num2*=10;
                        flag[j]=cc;
                        // chai[j]='g';
                        stg[hold+j+1]='g';
                        //printf("n:%d\n", num2);
                    }
                    if(stg[hold+j+1]==')') stg[hold+j+1]='g';
                    num2=num2/10;
                    //printf("num2: %d\n", num2);
                }
                else{
                    num2=aray[flag[i+1]];
                }
                // printf("n:%d\n", num2);
                num1=0;
                a=1;
                if(flag[i-1]==0){
                    for(j=i-1;chai[j]!='&' && chai[j]!='|' && chai[j]!='^' && chai[j]!='%' && j>=0;j--){
                        num1+=((chai[j]-'0')*a);
                        a*=10;
                        flag[j]=cc;
                        //chai[j]='g';
                        stg[hold+j+1]='g';
                    }
                    mn=hold+j+2;
                }
                else{
                    num1=aray[flag[i-1]];
                }
                //printf("num1:%d num2:%d\n", num1, num2);
                ans=(num1 % num2);
                aray[cc]=ans;
                for(b=hold+i;stg[b]=='g';b++){
                    aray[flag[b-hold]]=ans;
                }
                for(b=hold+i;stg[b]=='g';b--){
                    aray[flag[b-hold]]=ans;
                }
                //printf("ans:%d %d %d\n", ans, num1, num2);
                --smod;
                cc++;
                break;
            }
            else if((chai[i]=='&' && smod==0 && sand) && flag[i]==0){
                //chai[i]='g';
                flag[i]=cc;
                stg[hold+i+1]='g';
                num2=0;
                if(flag[i+1]==0){
                    for(j=i+1;chai[j]!='&' && chai[j]!='|' && chai[j]!='^' && chai[j]!='%' && j<holde-hold-1;j++){
                        num2+=((chai[j]-'0'));
                        num2*=10;
                        flag[j]=cc;
                        //chai[j]='g';
                        stg[hold+j+1]='g';
                        // printf("%d\n", num2);
                    }
                    if(stg[hold+j+1]==')') stg[hold+j+1]='g';
                    num2=num2/10;
                    //  printf("%d\n", num2);
                }
                else{
                    num2=aray[flag[i+1]];
                }
                // printf("n:%d\n", num2);
                num1=0;
                a=1;
                if(flag[i-1]==0){
                    for(j=i-1;chai[j]!='&' && chai[j]!='|' && chai[j]!='^' && chai[j]!='%' && j>=0;j--){
                        num1+=((chai[j]-'0')*a);
                        a*=10;
                        flag[j]=cc;
                        //chai[j]='g';
                        stg[hold+j+1]='g';
                    }
                    mn=hold+j+2;
                }
                else{
                    num1=aray[flag[i-1]];
                }
                //printf("num1:%d num2:%d\n", num1, num2);
                ans=(num1 & num2);
                aray[cc]=ans;
                for(b=hold+i;stg[b]=='g';b++){
                    aray[flag[b-hold]]=ans;
                }
                for(b=hold+i;stg[b]=='g';b--){
                    aray[flag[b-hold]]=ans;
                }
                --sand;
                cc++;
                break;
            }
            else if((chai[i]=='^' && smod==0 && sand==0 && sxor) && flag[i]==0){
                //chai[i]='g';
                flag[i]=cc;
                stg[hold+i+1]='g';
                num2=0;
                if(flag[i+1]==0){
                    for(j=i+1;chai[j]!='&' && chai[j]!='|' && chai[j]!='^' && chai[j]!='%' && j<holde-1-hold;j++){
                        num2+=((chai[j]-'0'));
                        num2*=10;
                        flag[j]=cc;
                        //chai[j]='g';
                        stg[hold+j+1]='g';
                        //  printf("%d\n", num2);
                    }
                    if(stg[hold+j+1]==')') stg[hold+j+1]='g';
                    num2=num2/10;
                    //printf("f%d\n", num2);
                }
                else{
                    num2=aray[flag[i+1]];
                }
                // printf("n:%d\n", num2);
                num1=0;
                a=1;
                if(flag[i-1]==0){
                    for(j=i-1;chai[j]!='&' && chai[j]!='|' && chai[j]!='^' && chai[j]!='%' && j>=0;j--){
                        num1+=((chai[j]-'0')*a);
                        a*=10;
                        flag[j]=cc;
                        //chai[j]='g';
                        stg[hold+j+1]='g';
                    }
                    mn=hold+j+2;
                }
                else{
                    num1=aray[flag[i-1]];
                }
                // printf("%d\n", num1);
                ans=(num1^num2);
                //printf("xorans:%d %d %d\n", ans, num1, num2);
                aray[cc]=ans;
                for(b=hold+i;stg[b]=='g';b++){
                    aray[flag[b-hold]]=ans;
                }
                for(b=hold+i;stg[b]=='g';b--){
                    aray[flag[b-hold]]=ans;
                }
                --sxor;
                cc++;
                break;
            }
            else if((chai[i]=='|' && smod==0 && sand==0 && sxor==0 && sor) && flag[i]==0){
                // chai[i]='g';
                flag[i]=cc;
                stg[hold+i+1]='g';
                num2=0;
                if(flag[i+1]==0){
                    for(j=i+1;chai[j]!='&' && chai[j]!='|' && chai[j]!='^' && chai[j]!='%' && j<holde-1-hold;j++){
                        num2+=((chai[j]-'0'));
                        num2*=10;
                        flag[j]=cc;
                        // chai[j]='g';
                        stg[hold+j+1]='g';
                        //  printf("%d\n", num2);
                    }
                    if(stg[hold+j+1]==')') stg[hold+j+1]='g';
                    num2=num2/10;
                    //  printf("%d\n", num2);
                }
                else{
                    num2=aray[flag[i+1]];
                }
                //   printf("n:%d\n", num2);
                num1=0;
                a=1;
                if(flag[i-1]==0){
                    for(j=i-1;chai[j]!='&' && chai[j]!='|' && chai[j]!='^' && chai[j]!='%' && j>=0;j--){
                        num1+=((chai[j]-'0')*a);
                        a*=10;
                        flag[j]=cc;
                        //chai[j]='g';
                        stg[hold+j+1]='g';
                    }
                    mn=hold+j+2;
                }
                else{
                    num1=aray[flag[i-1]];
                }
                // printf("%d\n", num1);
                ans=(num1|num2);
                aray[cc]=ans;
                for(b=hold+i;stg[b]=='g';b++){
                    aray[flag[b-hold]]=ans;
                }
                for(b=hold+i;stg[b]=='g';b--){
                    aray[flag[b-hold]]=ans;
                }
                --sor;
                cc++;
                break;
            }
            puts(stg);
            //printf("ans:%d %s\n", ans, given);

        }
    }
    //puts(given);
    itoa(ans,strr,10);
    printf("ans: %d\n", ans);
    //printf("%s\n", strr);
    for(k=hold,j=0;strr[j];k++,j++){
        stg[k]=strr[j];
    }
    //puts(given);
    binpaste(stg,k);
    printf("\n%d %s\n", ans, stg);
    itoa(ans,res,10);

}

void bininput()
{
    int i, j, k, a, b, l, brac=0, cnt=0, yy;
    char aray[100]={0},foul[100]={0};
    for(i=0;cop[i];i++){
        cop[i]='\0';
    }
    if(str[0]!='\0'){
        // gets(str);
        printf("new:%s\n", sss);
        strcpy(stg,sss);
        printf("neww:%s\n",stg);
        l=strlen(stg);
        cop[0]='(';
        strcat(cop,stg);
        cop[l+1]=')';
        cop[l+2]='\0';

        strcpy(stg,cop);
        l=strlen(stg);
        //printf("iL %s\n", given);
        for(i=0;stg[i];i++){
            if(stg[i]=='(' || stg[i]==')') brac++;
            // else if(!isdigit(given[i])) cnt++;
        }

        if(brac){
            while(brac){
                l=strlen(stg);
                //printf("l:%d\n", l);
                for(i=l-1;i>-1;i--){
                    if(stg[i]==')' ){
                        j=i;
                    }
                    if(stg[i]=='(' ){
                        printf("%s\n", stg);
                        //printf("i:%d j:%d\n", i, j);
                        binashol(&stg[i+1],&stg[j-1], i, j);
                        aray[i]=1;
                        aray[j]=1;
                        break;
                    }
                }
                brac=brac-2;
            }
        }
        printf("%s\n", stg);
        if(mod==1){
            tot=atoi(stg);
            strcpy(res,stg);
        }
        else if(mod==2) {
            tot=atoi(stg);
            itoa(tot,res,16);
        }
        else if(mod==3) {
            tot=atoi(stg);
            itoa(tot,res,8);
        }
        else if(mod==4) {
            tot=atoi(stg);
            itoa(tot,res,2);
        }
        //strcpy(res,stg);
        // printf("%s", str);
    }



}




void iMouseMove(int mx, int my)
{
    movex=mx;
    movey=my;
    //printf("%d %d\n", movex, movey);
}

void iMouse(int button, int state, int mx, int my)
{
    gbutton=button;
    gstate=state;
    gmx=mx;
    gmy=my;
    if(gmx>=10&&gmx<=456&&gmy>=386&&gmy<=464&&mode==0)mode=1;
    else if(gmx>=14&&gmx<=534&&gmy>=245&&gmy<=333&&mode==0)mode=2;
    else if((mode==1 || mode==2) && (mx>=630 && mx<=680 && my>=670 && my<=686) &&  (button==GLUT_LEFT_BUTTON && state==0)){

        mode=0;
        memset(ch,0,sizeof ch);
        memset(evaluate,0,sizeof evaluate);
        memset(uttor,0,sizeof uttor);
        memset(res,0,sizeof res);
        memset(str,0,sizeof str);
        memset(sss,0,sizeof sss);
        memset(syntax,0,sizeof syntax);
        memset(exam,0,sizeof exam);
        flag=0;
        flag1=0;
        br_push=0;
        i=0;l=0;tot=0;
    }
    else if(mx>=273 && mx<=323 && my>=410 && my<=470 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2 && mod==2) str[i++]='A';
    }
    else if(gbutton==0 && gstate==0 && gmx>=334 && gmx<=384 && gmy>=410 && gmy<=470)
    {
        strcat(ch,"e^(");
        flag+=3;
        syntax[br_push++]='(';
        strcat(evaluate,"2.718281828^(");
        flag1+=13;
    }
    else if(gbutton==0 && gstate==0 && gmx>=456 && gmx<=506 && gmy>=410 && gmy<=470)
    {
        rad_deg=0;
    }
    else if(gbutton==0 && gstate==0 && gmx>=517 && gmx<=567 && gmy>=410 && gmy<=470 && mode==1)
    {
        rad_deg=1;
    }
    else if(gbutton==0 && gstate==0 && gmx>=578 && gmx<=578+50 && gmy>=80 && gmy<=80+125 && mode==1)
    {
        memset(ch,0,sizeof ch);
        flag=0;
        flag1=0;
        shesh=0;
        foo(syntax,0,0,0,0);
        if(shesh==0)
        {
            puts(syntax);
            memset(uttor,0,sizeof uttor);
            memset(evaluate,0,sizeof evaluate);
            memset(syntax,0,sizeof syntax);
            br_push=0;
            strcpy(uttor,"Syntax Error");
        }
        else {
            if(vagshesh==0){
                strcat(ch,"(");
                strcat(ch,evaluate);
                strcat(ch,")");
                memset(evaluate,0,sizeof evaluate);
                strcpy(evaluate,ch);
                memset(ch,0,sizeof ch);
                int len,i;
                len=strlen(evaluate);
                //cout<<evaluate<<endl;
                char *ptr=NULL;
                for(i=len-1;i>-1;i--)
                {
                    //cout<<"-_-"<<endl;

                    memset(stri,0,sizeof stri);
                    //cout<<"HIHI"<<endl;
                    //cout<<"htha"<<endl;
                    if(evaluate[i]=='(')
                    {
                        memset(matha,0,sizeof matha);
                        //cout<<evaluate<<" uff"<<endl;
                        int sun=0;
                        //printf("%d eibar\n",i);
                        double ans;
                        int j,k;
                        ptr=&evaluate[i];
                        //strcpy(str,evaluate);
                        while(1)
                        {
                            //cout<<"HIHI"<<endl;
                            if(*ptr==')'||*ptr==0)break;
                            ptr++;
                        }
                        //cout<<*ptr<<endl;
                        if(*ptr==')')ptr++;
                        //cout<<(int)*ptr<<"-_-"<<endl;

                        strcpy(matha,evaluate);
                        ans=expression(&matha[i+1],0);
                        //cout<<evaluate<<" er"<<endl;
                        if(i==0);
                        else if(evaluate[i-1]=='t'&&evaluate[i-2]=='c')
                        {
                            if(ans==(int)ans&&ans>-1)ans=fact((int)ans);
                            else {jhamela=1;break;}
                            //cout<<ans;
                            i-=4;
                        }
                        else if(evaluate[i-1]=='n'&&evaluate[i-2]=='i')
                        {
                            if(i-4<0||evaluate[i-4]!='a')
                            {
                                if(rad_deg==0)ans=sin(ans*pi/180);
                                else ans=sin(ans);
                                i-=3;
                            }
                            else
                            {
                                if(ans>=-1&&ans<=1&&rad_deg==0)ans=180/pi*asin(ans);
                                else if(ans>=-1&&ans<=1)ans=asin(ans);
                                else {jhamela=1;break;}
                                i-=4;
                            }
                        }
                        else if(evaluate[i-1]=='s'&&evaluate[i-2]=='o')
                        {
                            if(i-4<0||evaluate[i-4]!='a')
                            {
                                if(rad_deg==0)ans=cos(ans*pi/180);
                                else ans=cos(ans);
                                i-=3;
                            }
                            else
                            {
                                if(ans>=-1&&ans<=1&&rad_deg==0)ans=180/pi*acos(ans);
                                else if(ans>=-1&&ans<=1)ans=acos(ans);
                                else {jhamela=1;break;}
                                i-=4;
                            }
                        }
                        else if(evaluate[i-1]=='n'&&evaluate[i-2]=='a')
                        {
                            if(i-4<0||evaluate[i-4]!='a')
                            {
                                if(rad_deg==0&&((int)ans)%90!=0)ans=tan(ans*pi/180);
                                else if(rad_deg==1&&(int)(ans*pi/180)%90==0)ans=tan(ans);
                                else {jhamela=1;break;}
                                i-=3;
                            }
                            else
                            {
                                if(rad_deg==0)ans=180/pi*atan(ans);
                                else ans=atan(ans);
                                i-=4;
                            }
                        }
                        else if(evaluate[i-1]=='n'&&evaluate[i-2]=='l')
                        {
                            if(ans>0)ans=log(ans);
                            else {jhamela=1;break;}
                            i-=2;
                        }
                        else if(evaluate[i-1]=='h'&&evaluate[i-2]=='n'&&evaluate[i-3]=='a')
                        {
                            if(i-5<0||evaluate[i-5]!='a')
                            {
                                ans=tanh(ans);
                                i-=4;
                            }
                            else
                            {
                                if(ans>-1&&ans<1)ans=atanh(ans);
                                else {jhamela=1;break;}
                                i-=5;
                            }
                        }
                        else if(evaluate[i-1]=='h'&&evaluate[i-2]=='n'&&evaluate[i-3]=='i')
                        {
                            if(i-5<0||evaluate[i-5]!='a')
                            {
                                ans=sinh(ans);
                                i-=4;
                            }
                            else
                            {
                                ans=asinh(ans);
                                i-=5;
                            }
                        }
                        else if(evaluate[i-1]=='h'&&evaluate[i-2]=='s'&&evaluate[i-3]=='o')
                        {
                            if(i-5<0||evaluate[i-5]!='a')
                            {
                                ans=cosh(ans);
                                i-=4;
                            }
                            else
                            {
                                if(ans>=1)ans=acosh(ans);
                                else {jhamela=1;break;}
                                i-=5;
                            }
                        }
                        else if(evaluate[i-1]=='g'&&evaluate[i-2]=='o')
                        {
                            if(ans>0)ans=log10(ans);
                            else {jhamela=1;break;}
                            i-=3;
                        }
                        if(*ptr=='^')
                        {
                            tutut=1;
                            char tutu[40];
                            int mama=0,is=0;
                            if(*(ptr+1)=='-'){is=1;ptr++;}
                            while(1)
                            {

                                if(!isdigit(*++ptr)&&*ptr!='.')break;
                                tutu[mama++]=*(ptr);
                            }
                            tutu[mama]=0;//printf("%lf %d",ans,is);
                            if((ans!=0||atof(tutu)!=0)&&is==0)ans=pow(ans,atof(tutu));
                            else if((ans!=0||atof(tutu)!=0)&&is==1)ans=pow(ans,-atof(tutu));
                            else {jhamela=1;break;}

                        }
                        else if(evaluate[i-1]=='^')
                        {

                            if(!isdigit(evaluate[i-2]));
                            else
                            {
                                tutut=1;
                                char tutu[40];
                                int j,mama=0;
                                for(j=i-2;;j--)
                                {
                                    if(!isdigit(evaluate[j])&&evaluate[j]!='.')break;
                                    tutu[mama++]=evaluate[j];
                                }
                                tutu[mama]=0;
                                strrev(tutu);
                                i=j+1;
                                if(ans!=0||atof(tutu)!=0)ans=pow(atof(tutu),ans);
                                else {jhamela=1;break;}
                                //cout<<ans<<endl;
                                //cout<<evaluate<<endl;
                            }
                        }

                        for(j=0;j<i;j++)
                            stri[j]=evaluate[j];
                        //strcpy(evaluate,matha);
                        //ans=expression(&evaluate[i+2],0);
                        //cout<<ans<<endl;
                        if(tutut==1){memset(matha,0,sizeof matha);
                        strcat(matha,"(");}
                        sprintf(hayre,"%.09lf",ans);
                        if(tutut==1)
                        {
                            strcat(matha,hayre);
                            strcat(matha,")");
                        }
                        //cout<<hayre<<" :3"<<endl;
                        //cout<<itoa((int)ans,w,10)<<endl;
                        //cout<<w<<endl;
                        for(k=0;k<strlen(hayre)&&tutut==0;k++)
                            stri[j++]=hayre[k];
                        for(k=0;k<strlen(matha)&&tutut==1;k++)
                            stri[j++]=matha[k];
                        //cout<<"MIU"<<endl;
                        //else strcat(str,w);
                        //cout<<str<<"lolo"<<endl;
                        strcat(stri,ptr);
                        memset(evaluate,0,sizeof evaluate);
                        strcpy(evaluate,stri);
                        i=strlen(evaluate);
                        //cout<<i<<" uff"<<endl;
                        //cout<<evaluate<<" hmm"<<endl;
                        //printf("-_-\n");printf("-_-\n");
                        ptr=NULL;
                        tutut=0;
                    }

                    //printf("-_-\n");
                }
                memset(uttor,0,sizeof uttor);
                strcpy(uttor,evaluate);
                memset(evaluate,0,sizeof evaluate);
            }

            else
            {
                char *arr1=strtok(evaluate,"%");
                char *arr2=strtok(NULL,"%");
                if(atoi(arr2)!=0)sprintf(uttor,"%d",atoi(arr1)%atoi(arr2));
                else jhamela=1;
            }
            if(jhamela==1||strcmp(uttor,"1.#INF00000")==0)strcpy(uttor,"Math error");
            jhamela=0;
            vagshesh=0;
        }}
    else if(gbutton==0 && gstate==0 && gmx>=395 && gmx<=445 && gmy>=410 && gmy<=470 && mode==1)
    {
        char kopal[100];
        if(gorom==0)sprintf(kopal,"%d",atoi(uttor));
        //printf("%lf",atof(uttor));
        if(gorom==1)
        {
            sprintf(kopal,"%.09lf",atof(uttor)-atoi(uttor));
        }
        memset(uttor,0,sizeof uttor);
        strcpy(uttor,kopal);
    }
    else if(gbutton==0 && gstate==0 && gmx>=578 && gmx<=628 && gmy>=410 && gmy<=470 && mode==1)
    {
        char arr[12];
        sprintf(arr,"%.09lf",pi);
        if(gorom==0)strcat(ch,"pi");
        else
        {
            strcat(ch,"2*pi");
            sprintf(arr,"%.09lf",2*pi);
            flag+=2;
        }
        flag+=2;
        strcat(evaluate,arr);
        flag1+=strlen(arr);
    }
    else if(gbutton==0 && gstate==0 && gmx>=80 && gmx<=130 && gmy>=80+66 && gmy<=140+66 && mode==1)
    {
        if(gorom==0)
        {
            strcat(ch,"tanh(");
            strcat(evaluate,"tanh(");
            flag+=5;
            flag1+=5;
        }
        else
        {
            strcat(ch,"atanh(");
            strcat(evaluate,"atanh(");
            flag+=6;
            flag1+=6;
        }
        syntax[br_push++]='(';
    }
    else if(gbutton==0 && gstate==0 && gmx>=80 && gmx<=130 && gmy>=80+66+66 && gmy<=140+66+66 && mode==1)
    {
        syntax[br_push++]='(';
        if(gorom==0)
        {
            strcat(ch,"cosh(");
            strcat(evaluate,"cosh(");
            flag+=5;
            flag1+=5;
        }
        else
        {
            strcat(ch,"acosh(");
            strcat(evaluate,"acosh(");
            flag+=6;
            flag1+=6;
        }
    }
    else if(gbutton==0 && gstate==0 && gmx>=80 && gmx<=130 && gmy>=80+66+66*2 && gmy<=140+66+66*2 && mode==1)
    {
        syntax[br_push++]='(';
        if(gorom==0)
        {
            strcat(ch,"sinh(");
            strcat(evaluate,"sinh(");
            flag+=5;
            flag1+=5;
        }
        else
        {
            strcat(ch,"asinh(");
            strcat(evaluate,"asinh(");
            flag+=6;
            flag1+=6;
        }
    }
    else if(gbutton==0 && gstate==0 && gmx>=578 && gmx<=628 && gmy>=212 && gmy<=272 && mode==1)
    {
        syntax[br_push++]='(';
        strcat(ch,"1/(");
        strcat(evaluate,"1/(");
        flag+=3;
        flag1+=3;
    }
    else if(gbutton==0 && gstate==0 && gmx>=80 && gmx<=130 && gmy>=80+66+66*3 && gmy<=140+66+66*3 && mode==1)
    {
        if(gorom==0)gorom=1;
        else gorom=0;
    }
    else if(mx>=273 && mx<=323 && my>=344 && my<=404 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2 && mod==2)str[i++]='B';
        else if(mode==1)
        {
            ch[flag++]=')';
            evaluate[flag1++]=')';
            syntax[br_push++]=')';
        }
    }
    else if(mx>=273 && mx<=323 && my>=278 && my<=338 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2 && mod==2)str[i++]='C';
        else if(mode==1)
        {
            ch[flag++]='!';
            int mi=flag-2;
            if(isdigit(ch[mi]))
            {
                char arr[100];
                int k=0;
                while(isdigit(ch[mi--]))
                {
                    arr[k++]=ch[mi+1];
                    evaluate[--flag1]=0;
                }
                arr[k]=0;
                strrev(arr);
                strcat(evaluate,"fact(");
                strcat(evaluate,arr);
                strcat(evaluate,")");
                flag1+=strlen(arr)+6;
            }
            else
            {
                int hihi=1;
                char arr[100];
                int k=0;
                int miu=flag-2;
                do
                {
                    arr[k++]=ch[miu--];evaluate[--flag1]=0;
                    if(ch[miu]==')')hihi++;
                    else if(ch[miu]=='(')hihi--;

                }while(hihi);
                arr[k]=0;
                strrev(arr);
                strcat(evaluate,"fact(");
                strcat(evaluate,arr);
                strcat(evaluate,")");
                flag1+=strlen(arr)+6;
            }
        }
    }
    else if(mx>=273 && mx<=323 && my>=212 && my<=272 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2 && mod==2) str[i++]='D';
        else if(mode==1)
        {
            syntax[br_push++]='(';
            strcat(ch,"^(1/");
            strcat(evaluate,"^(1/");
            flag+=4;
            flag1+=4;
        }
    }
    else if(mx>=273 && mx<=323 && my>=146 && my<=206 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2 && mod==2)str[i++]='E';
        else if(mode==1)
        {
            strcat(ch,"^(1/3)");
            strcat(evaluate,"^(1/3)");
            flag+=6;
            flag1+=6;
        }
    }
    else if(mx>=273 && mx<=323 && my>=80 && my<=140 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2 && mod==2)str[i++]='F';
        else if(mode==1)
        {
            syntax[br_push++]='(';
            strcat(ch,"10^(");
            strcat(evaluate,"10^(");
            flag+=4;
            flag1+=4;
        }
    }

    else if(mx>=334 && mx<=384 && my>=80 && my<=140 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2)str[i++]='0';
        else if(mode==1)
        {
            ch[flag++]='0';
            evaluate[flag1++]='0';
        }
    }
    else if(mx>=334 && mx<=384 && my>=146 && my<=206 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2)str[i++]='1';
        else if(mode==1)
        {
            ch[flag++]='1';
            evaluate[flag1++]='1';
        }
    }
    else if(mx>=334 && mx<=384 && my>=212 && my<=272 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2 && (mod==1 || mod==2 || mod==3))str[i++]='4';
        else if(mode==1)
        {
            ch[flag++]='4';
            evaluate[flag1++]='4';
        }
    }
    else if(mx>=334 && mx<=384 && my>=278 && my<=338 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2 && (mod==1 || mod==2 || mod==3))str[i++]='7';
        else if(mode==1)
        {
            ch[flag++]='7';
            evaluate[flag1++]='7';
        }
    }
    else if(mx>=334 && mx<=384 && my>=344 && my<=404 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2){str[--i]='\0';
        for(in=0;in<strlen(res);in++) res[in]='\0';}
        else if(mode==1)
        {
            if(ch[flag-1]=='('||ch[flag-1]==')')syntax[--br_push]=0;
            if(flag>0){ch[--flag]=0;
            evaluate[--flag1]=0;}
        }
    }

    else if(mx>=395 && mx<=445 && my>=146 && my<=206 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2 && (mod==1 || mod==2 || mod==3))str[i++]='2';
        else if(mode==1)
        {
            ch[flag++]='2';
            evaluate[flag1++]='2';
        }
    }
    else if(mx>=395 && mx<=445 && my>=212 && my<=272 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2 && (mod==1 || mod==2 || mod==3))str[i++]='5';
        else if(mode==1)
        {
            ch[flag++]='5';
            evaluate[flag1++]='5';
        }
    }
    else if(mx>=395 && mx<=445 && my>=278 && my<=338 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2 && (mod==1 || mod==2))str[i++]='8';
        else if(mode==1)
        {
            ch[flag++]='8';
            evaluate[flag1++]='8';
        }
    }

    else if(mx>=456 && mx<=506 && my>=146 && my<=206 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2 && (mod==1 || mod==2 || mod==3))str[i++]='3';
        else if(mode==1)
        {
            ch[flag++]='3';
            evaluate[flag1++]='3';
        }

    }
    else if(mx>=456 && mx<=506 && my>=212 && my<=272 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2&&(mod==1 || mod==2 || mod==3))str[i++]='6';
        else if(mode==1)
        {
            ch[flag++]='6';
            evaluate[flag1++]='6';
        }
    }
    else if(mx>=456 && mx<=506 && my>=278 && my<=338 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2 && (mod==1 || mod==2))str[i++]='9';
        else if(mode==1)
        {
            ch[flag++]='9';
            evaluate[flag1++]='9';
        }
    }
    else if(mx>=456 && mx<=506 && my>=80 && my<=140 && button==GLUT_LEFT_BUTTON && state==0){
        //if(mode==2)str[i++]='.';
        if(mode==1)
        {
            ch[flag++]='.';
            evaluate[flag1++]='.';
        }
    }

    else if(mx>=151 && mx<=201 && my>=344 && my<=404 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2)str[i++]='(';
        else if(mode==1)
        {
            syntax[br_push++]='(';
            strcat(ch,"ln(");
            strcat(evaluate,"ln(");
            flag+=3;
            flag1+=3;
        }
    }
    else if(mx>=212 && mx<=262 && my>=344 && my<=404 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2)str[i++]=')';
        else if(mode==1)
        {
            ch[flag++]='(';
            evaluate[flag1++]='(';
            syntax[br_push++]='(';
        }
    }

    else if(mx>=395 && mx<=445 && my>=344 && my<=404 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2){for(in=0;in<i;in++) str[in]='\0';
        for(in=0;in<strlen(res);in++) res[in]='\0';
        for(in=0;sss[in];in++) sss[in]='\0';
        memset(exam,0,sizeof exam);
        i=0;l=0;tot=0;}
        else if(mode==1)
        {
            memset(ch,0,sizeof ch);
            memset(uttor,0,sizeof uttor);
            memset(evaluate,0,sizeof evaluate);
            flag=0;
            flag1=0;
        }

    }
    else if(mx>=456 && mx<=506 && my>=344 && my<=404 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2){for(in=0;in<i;in++) str[in]='\0';
        for(in=0;in<strlen(res);in++) res[in]='\0';
        for(in=0;sss[in];in++) sss[in]='\0';
        memset(exam,0,sizeof exam);
        i=0;l=0;tot=0;}
        else if(mode==1)
        {
            memset(ch,0,sizeof ch);
            memset(uttor,0,sizeof uttor);
            memset(evaluate,0,sizeof evaluate);
            flag=0;
            flag1=0;
        }
    }

    else if(mx>=578 && mx<=628 && my>=278 && my<=338 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2)str[i++]='%';
        else if(mode==1)
        {
            //ch[flag++]='h';
        }
    }
    else if(mx>=578 && mx<=628 && my>=344 && my<=404 && button==GLUT_LEFT_BUTTON && state==0){
        //if(mode==2){str[i++]='s';str[i++]='q';str[i++]='r';str[i++]='t';}
        if(mode==1)
        {
            strcat(ch,"^(1/2)");
            strcat(evaluate,"^(1/2)");
            flag+=6;
            flag1+=6;
        }
    }

    else if(mx>=517 && mx<=567 && my>=80 && my<=140 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2)str[i++]='+';
        else if(mode==1)
        {
            ch[flag++]='+';
            evaluate[flag1++]='+';
        }
    }
    else if(mx>=517 && mx<=567 && my>=146 && my<=206 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2)str[i++]='-';
        else if(mode==1)
        {
            ch[flag++]='-';
            evaluate[flag1++]='-';
        }
    }
    else if(mx>=517 && mx<=567 && my>=212 && my<=272 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2)str[i++]='*';
        else if(mode==1)
        {
            ch[flag++]='*';
            evaluate[flag1++]='*';
        }
    }
    else if(mx>=517 && mx<=567 && my>=278 && my<=338 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2)str[i++]='/';
        else if(mode==1)
        {
            ch[flag++]='/';
            evaluate[flag1++]='/';
        }
    }
    else if(mx>=578 && mx<=628 && my>=80 && my<=206 && button==GLUT_LEFT_BUTTON && state==0){
        modar=0;
        str[i]='\0';
        for(in=0;str[in];in++){
            if(!((str[in]>='0' && str[in]<='9') || (str[in]>='a' && str[in]<='f') || (str[in]>='A' && str[in]<='F'))) break;
        }
        if(in==strlen(str)) {
            strcpy(res,str);
        }
        else{
            for(in=0;str[in];in++){
                if(str[in]=='&' || str[in]=='|' || str[in]=='^' || str[in]=='~' || str[in]=='%') {
                    modar=1;
                }
                else if(str[in]=='+' || str[in]=='-' || str[in]=='/' || str[in]=='*' ){
                    modar=2;
                }

            }
            /*for(in=0;str[in];in++){
            if(!(str[in]>='0' && str[in]<='9')) {
            break;
            }
            }*/

            if(modar==1){
                if(mod==1){
                    strcpy(sss,str);
                    bininput();
                }
                else if(mod==2){
                    hexatodec(str);
                    bininput();
                }
                else if(mod==3){
                    octaltodec(str);
                    bininput();
                }
                else if(mod==4){
                    //printf("what");
                    binarytodec(str);
                    bininput();
                }
            }
            else if(modar==2){
                if(mod==1){
                    strcpy(sss,str);
                    shihab();
                }
                else if(mod==2){
                    hexatodec(str);
                    shihab();
                }
                else if(mod==3){
                    octaltodec(str);
                    shihab();
                }
                else if(mod==4){
                    //printf("what");
                    binarytodec(str);
                    shihab();
                }
            }

        }
    }



    else if(mx>=90 && mx<=140 && my>=365 && my<=445 && button==GLUT_LEFT_BUTTON && state==0 && mode==2){
        mod=4;int x;
        memset(exam,0,sizeof exam);
        if(res[0]!='\0'){
            itoa(tot,res,2);
        }
        if(modar==2)
        shihab();

        //x=atoi(res);
        //itoa(x,res,2);
    }
    else if(mx>=90 && mx<=140 && my>=270 && my<=350 && button==GLUT_LEFT_BUTTON && state==0 && mode==2){
        mod=3;
        memset(exam,0,sizeof exam);
        if(res[0]!='\0'){
            itoa(tot,res,8);
        }
        if(modar==2)
        shihab();

    }
    else if(mx>=90 && mx<=140 && my>=175 && my<=255 && button==GLUT_LEFT_BUTTON && state==0 && mode==2){
        mod=1;
        memset(exam,0,sizeof exam);
        if(res[0]!='\0'){
            itoa(tot,res,10);
        }
        if(modar==2)
        shihab();

    }
    else if(mx>=90 && mx<=140 && my>=80 && my<=160 && button==GLUT_LEFT_BUTTON && state==0 && mode==2){
        mod=2;
        memset(exam,0,sizeof exam);
        if(res[0]!='\0'){
            itoa(tot,res,16);
        }
        if(modar==2)
        shihab();

    }

    else if(mx>=212 && mx<=262 && my>=80 && my<=140 && button==GLUT_LEFT_BUTTON && state==0 ){
        if(mode==2)str[i++]='&';
        else if(mode==1)
        {
            syntax[br_push++]='(';
            strcat(ch,"log(");
            strcat(evaluate,"log(");
            flag+=4;
            flag1+=4;
        }
    }
    else if(mx>=212 && mx<=262 && my>=212 && my<=272 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2)str[i++]='^';
        else if(mode==1)
        {
            syntax[br_push++]='(';
            strcat(ch,"^(");
            strcat(evaluate,"^(");
            flag+=2;
            flag1+=2;
        }
    }
    else if(mx>=151 && mx<=201 && my>=212 && my<=272 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2)str[i++]='|';
        else if(mode==1)
        {
            syntax[br_push++]='(';
            //cos
            if(gorom==0)
            {
                strcat(ch,"cos(");
                strcat(evaluate,"cos(");
                flag+=4;
                flag1+=4;
            }
            else
            {
                strcat(ch,"acos(");
                strcat(evaluate,"acos(");
                flag+=5;
                flag1+=5;
            }
        }
    }
    else if(mx>=212 && mx<=262 && my>=410 && my<=470 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2)str[i++]='%';
        else if(mode==1)
        {
            // kisu na
        }
    }

    else if(mx>=151 && mx<=201 && my>=146 && my<=206 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2){if(sss[0]=='\0') strcpy(sss,str);
        leftshift(sss);}
        else if(mode==1)
        {
            syntax[br_push++]='(';
            // tan
            if(gorom==0)
            {
                strcat(ch,"tan(");
                strcat(evaluate,"tan(");
                flag+=4;
                flag1+=4;
            }
            else
            {
                strcat(ch,"atan(");
                strcat(evaluate,"atan(");
                flag+=5;
                flag1+=5;
            }
        }
    }
    else if(mx>=212 && mx<=262 && my>=146 && my<=206 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2){if(sss[0]=='\0') strcpy(sss,str);
        rightshift(sss);}
        else if(mode==1)
        {
            // cube
            strcat(ch,"^(3)");
            strcat(evaluate,"^(3)");
            flag+=4;
            flag1+=4;
        }
    }
    else if(mx>=151 && mx<=201 && my>=80 && my<=140 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2){
            if(res[0]!='\0'){int x;
            x=atoi(res);
            x=-(x+1);
            itoa(x,res,10);}
            else str[i++]='~';}
        else if(mode==1)
        {
            // mod
            ch[flag++]='%';
            evaluate[flag1++]='%';
            vagshesh=1;
        }
    }

    else if(mx>=212 && mx<=262 && my>=278 && my<=338 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2){if(sss[0]=='\0') strcpy(sss,str);
        rightrotate(sss);}
        else if(mode==1)
        {
            // square
            strcat(ch,"^(2)");
            strcat(evaluate,"^(2)");
            flag+=4;
            flag1+=4;
        }
    }
    else if(mx>=151 && mx<=201 && my>=278 && my<=338 && button==GLUT_LEFT_BUTTON && state==0){
        if(mode==2){if(sss[0]=='\0') strcpy(sss,str);
        printf("sss:%s\n",sss);
        leftrotate(sss);}
        else if(mode==1)
        {
            syntax[br_push++]='(';
            //sin
            if(gorom==0)
            {
                strcat(ch,"sin(");
                strcat(evaluate,"sin(");
                flag+=4;
                flag1+=4;
            }
            else
            {
                strcat(ch,"asin(");
                strcat(evaluate,"asin(");
                flag+=5;
                flag1+=5;
            }
        }
    }
    if(mode==2){
        if(mx>=334 && mx<=384 && my>=410 && my<=470 && button==GLUT_LEFT_BUTTON && state==0){//MC
            for(in=0;in<3;in++) memory[in]=0;
        }
        else if(mx>=395 && mx<=445 && my>=410 && my<=470 && button==GLUT_LEFT_BUTTON && state==0){//MR
            char aj[100];
            itoa(memory[0],res,10);

        }
        else if(mx>=517 && mx<=567 && my>=410 && my<=470 && button==GLUT_LEFT_BUTTON && state==0){//M+
            int a=0,b;
            if(memory[0]!=0) a=memory[0];
            b=atoi(res);
            a=a+b;
            memory[0]=a;
        }
        else if(mx>=578 && mx<=628 && my>=410 && my<=470 && button==GLUT_LEFT_BUTTON && state==0){//M-
            int a=0,b;
            if(memory[0]!=0) a=memory[0];
            b=atoi(res);
            a=a-b;
            memory[0]=a;
        }
    }


}


void iKeyboard(unsigned char key)
{
    if(key=='z') exit(0);
    if(mode==2){
        if(key=='1') str[i++]='1';
        else if(key=='2') {
            if(mod==1 || mod==2 || mod==3) str[i++]='2';
        }
        else if(key=='3') {
            if(mod==1 || mod==2 || mod==3) str[i++]='3';
        }
        else if(key=='4') {
            if(mod==1 || mod==2 || mod==3) str[i++]='4';
        }
        else if(key=='5') {
            if(mod==1 || mod==2 || mod==3) str[i++]='5';
        }
        else if(key=='6') {
            if(mod==1 || mod==2 || mod==3) str[i++]='6';
        }
        else if(key=='7') {
            if(mod==1 || mod==2 || mod==3) str[i++]='7';
        }
        else if(key=='8') {
            if(mod==1 || mod==2) str[i++]='8';
        }
        else if(key=='9') {
            if(mod==1 || mod==2)str[i++]='9';
        }
        else if(key=='0') str[i++]='0';
        else if(key=='*') str[i++]='*';
        else if(key=='(') str[i++]='(';
        else if(key==')') str[i++]=')';
        else if(key=='+') str[i++]='+';
        else if(key=='-') str[i++]='-';
        else if(key=='&') str[i++]='&';
        else if(key=='^') str[i++]='^';
        else if(key=='%') str[i++]='%';
        else if(key=='|') str[i++]='|';
        else if(key=='!') str[i++]='!';
        else if(key=='/') str[i++]='/';
        else if(key=='~') str[i++]='~';
        else if(key=='\r') {
            str[i++]='\0';
            bininput();
        }
        else if(key=='a' && mod==2) str[i++]='a';
        else if(key=='A' && mod==2) str[i++]='A';
        else if(key=='b' && mod==2) str[i++]='b';
        else if(key=='B' && mod==2) str[i++]='B';
        else if(key=='c' && mod==2) str[i++]='c';
        else if(key=='C' && mod==2) str[i++]='C';
        else if(key=='d' && mod==2) str[i++]='d';
        else if(key=='D' && mod==2) str[i++]='D';
        else if(key=='e' && mod==2) str[i++]='e';
        else if(key=='E' && mod==2) str[i++]='E';
        else if(key=='f' && mod==2) str[i++]='f';
        else if(key=='F' && mod==2) str[i++]='F';
        else if(key=='\b'&&mode==2)
        {
            str[--i]=0;
			if(i<=0) i=0;
        }
        else if(key==',' && mode==2){
        printf("hoise");
        int modar=0;
        str[i]='\0';
        for(in=0;str[in];in++){
            if(!(str[in]>='0' && str[in]<='9')) break;
        }
        if(in==strlen(str)) strcpy(res,str);
        else{
            for(in=0;str[in];in++){
                if(str[in]=='&' || str[in]=='|' || str[in]=='^' || str[in]=='~' || str[in]=='%') {
                    modar=1;
                }
                else if(str[in]=='+' || str[in]=='-' || str[in]=='/' || str[in]=='*' ){
                    modar=2;
                }

            }
            /*for(in=0;str[in];in++){
            if(!(str[in]>='0' && str[in]<='9')) {
            break;
            }
            }*/

            if(modar==1){
                if(mod==1){
                    strcpy(sss,str);
                    bininput();
                }
                else if(mod==2){
                    hexatodec(str);
                    bininput();
                }
                else if(mod==3){
                    octaltodec(str);
                    bininput();
                }
                else if(mod==4){
                    //printf("what");
                    binarytodec(str);
                    bininput();
                }
            }
            else if(modar==2){
                if(mod==1){
                    strcpy(sss,str);
                    shihab();
                }
                else if(mod==2){
                    hexatodec(str);
                    shihab();
                }
                else if(mod==3){
                    octaltodec(str);
                    shihab();
                }
                else if(mod==4){
                    //printf("what");
                    binarytodec(str);
                    shihab();
                }
            }

        }
        }
    }

    if(key != '\b'&&key!='\n'&&key!='!' && key!=','&& key!='!'&& mode==1)
    {
        //do something with 'q'
        if(key=='('||key==')')
        {
            syntax[br_push++]=key;
        }
        if(key=='%')vagshesh=1;
        ch[flag++]=key;
        evaluate[flag1++]=key;
    }
    if(key=='!' && mode==1)
    {
            ch[flag++]='!';
            int mi=flag-2;
            if(isdigit(ch[mi]))
            {
                char arr[100];
                int k=0;
                while(isdigit(ch[mi--]))
                {
                    arr[k++]=ch[mi+1];
                    evaluate[--flag1]=0;
                }
                arr[k]=0;
                strrev(arr);
                strcat(evaluate,"fact(");
                strcat(evaluate,arr);
                strcat(evaluate,")");
                flag1+=strlen(arr)+6;
            }
            else
            {
                int hihi=1;
                char arr[100];
                int k=0;
                int miu=flag-2;
                do
                {
                    arr[k++]=ch[miu--];evaluate[--flag1]=0;
                    if(ch[miu]==')')hihi++;
                    else if(ch[miu]=='(')hihi--;

                }while(hihi);
                arr[k]=0;
                strrev(arr);
                strcat(evaluate,"fact(");
                strcat(evaluate,arr);
                strcat(evaluate,")");
                flag1+=strlen(arr)+6;
            }
        }
    if(key == '\b' && mode==1)
    {
        if(ch[flag-1]=='('||ch[flag-1]==')')syntax[--br_push]=0;
        if(flag>0){ch[--flag]=0;
        evaluate[--flag1]=0;}
    }
    if(key==','&&mode==1)
    {
        printf("%s",evaluate);
        memset(ch,0,sizeof ch);
        flag=0;
        flag1=0;
        shesh=0;
        foo(syntax,0,0,0,0);
        if(shesh==0)
        {
            puts(syntax);
            memset(uttor,0,sizeof uttor);
            memset(evaluate,0,sizeof evaluate);
            memset(syntax,0,sizeof syntax);
            br_push=0;
            strcpy(uttor,"Syntax Error");
        }
        else {
            if(vagshesh==0){
                strcat(ch,"(");
                strcat(ch,evaluate);
                strcat(ch,")");
                memset(evaluate,0,sizeof evaluate);
                strcpy(evaluate,ch);
                memset(ch,0,sizeof ch);
                int len,i;
                len=strlen(evaluate);
                //cout<<evaluate<<endl;
                char *ptr=NULL;
                for(i=len-1;i>-1;i--)
                {
                    //cout<<"-_-"<<endl;

                    memset(stri,0,sizeof stri);
                    //cout<<"HIHI"<<endl;
                    //cout<<"htha"<<endl;
                    if(evaluate[i]=='(')
                    {
                        memset(matha,0,sizeof matha);
                        //cout<<evaluate<<" uff"<<endl;
                        int sun=0;
                        //printf("%d eibar\n",i);
                        double ans;
                        int j,k;
                        ptr=&evaluate[i];
                        //strcpy(str,evaluate);
                        while(1)
                        {
                            //cout<<"HIHI"<<endl;
                            if(*ptr==')'||*ptr==0)break;
                            ptr++;
                        }
                        //cout<<*ptr<<endl;
                        if(*ptr==')')ptr++;
                        //cout<<(int)*ptr<<"-_-"<<endl;

                        strcpy(matha,evaluate);
                        ans=expression(&matha[i+1],0);
                        //cout<<evaluate<<" er"<<endl;
                        if(i==0);
                        else if(evaluate[i-1]=='t'&&evaluate[i-2]=='c')
                        {
                            if(ans==(int)ans&&ans>-1)ans=fact((int)ans);
                            else {jhamela=1;break;}
                            //cout<<ans;
                            i-=4;
                        }
                        else if(evaluate[i-1]=='n'&&evaluate[i-2]=='i')
                        {
                            if(i-4<0||evaluate[i-4]!='a')
                            {
                                if(rad_deg==0)ans=sin(ans*pi/180);
                                else ans=sin(ans);
                                i-=3;
                            }
                            else
                            {
                                if(ans>=-1&&ans<=1&&rad_deg==0)ans=180/pi*asin(ans);
                                else if(ans>=-1&&ans<=1)ans=asin(ans);
                                else {jhamela=1;break;}
                                i-=4;
                            }
                        }
                        else if(evaluate[i-1]=='s'&&evaluate[i-2]=='o')
                        {
                            if(i-4<0||evaluate[i-4]!='a')
                            {
                                if(rad_deg==0)ans=cos(ans*pi/180);
                                else ans=cos(ans);
                                i-=3;
                            }
                            else
                            {
                                if(ans>=-1&&ans<=1&&rad_deg==0)ans=180/pi*acos(ans);
                                else if(ans>=-1&&ans<=1)ans=acos(ans);
                                else {jhamela=1;break;}
                                i-=4;
                            }
                        }
                        else if(evaluate[i-1]=='n'&&evaluate[i-2]=='a')
                        {
                            if(i-4<0||evaluate[i-4]!='a')
                            {
                                if(rad_deg==0)ans=tan(ans*pi/180);
                                else ans=tan(ans);
                                i-=3;
                            }
                            else
                            {
                                if(rad_deg==0)ans=180/pi*atan(ans);
                                else ans=atan(ans);
                                i-=4;
                            }
                        }
                        else if(evaluate[i-1]=='n'&&evaluate[i-2]=='l')
                        {
                            if(ans>0)ans=log(ans);
                            else {jhamela=1;break;}
                            i-=2;
                        }
                        else if(evaluate[i-1]=='h'&&evaluate[i-2]=='n'&&evaluate[i-3]=='a')
                        {
                            if(i-5<0||evaluate[i-5]!='a')
                            {
                                ans=tanh(ans);
                                i-=4;
                            }
                            else
                            {
                                if(ans>-1&&ans<1)ans=atanh(ans);
                                else {jhamela=1;break;}
                                i-=5;
                            }
                        }
                        else if(evaluate[i-1]=='h'&&evaluate[i-2]=='n'&&evaluate[i-3]=='i')
                        {
                            if(i-5<0||evaluate[i-5]!='a')
                            {
                                ans=sinh(ans);
                                i-=4;
                            }
                            else
                            {
                                ans=asinh(ans);
                                i-=5;
                            }
                        }
                        else if(evaluate[i-1]=='h'&&evaluate[i-2]=='s'&&evaluate[i-3]=='o')
                        {
                            if(i-5<0||evaluate[i-5]!='a')
                            {
                                ans=cosh(ans);
                                i-=4;
                            }
                            else
                            {
                                if(ans>=1)ans=acosh(ans);
                                else {jhamela=1;break;}
                                i-=5;
                            }
                        }
                        else if(evaluate[i-1]=='g'&&evaluate[i-2]=='o')
                        {
                            if(ans>0)ans=log10(ans);
                            else {jhamela=1;break;}
                            i-=3;
                        }
                        if(*ptr=='^')
                        {
                            tutut=1;
                            char tutu[40];
                            int mama=0,is=0;
                            if(*(ptr+1)=='-'){is=1;ptr++;}
                            while(1)
                            {

                                if(!isdigit(*++ptr)&&*ptr!='.')break;
                                tutu[mama++]=*(ptr);
                            }
                            tutu[mama]=0;//printf("%lf %d",ans,is);
                            if((ans!=0||atof(tutu)!=0)&&is==0)ans=pow(ans,atof(tutu));
                            else if((ans!=0||atof(tutu)!=0)&&is==1)ans=pow(ans,-atof(tutu));
                            else {jhamela=1;break;}

                        }
                        else if(evaluate[i-1]=='^')
                        {

                            if(!isdigit(evaluate[i-2]));
                            else
                            {
                                tutut=1;
                                char tutu[40];
                                int j,mama=0;
                                for(j=i-2;;j--)
                                {
                                    if(!isdigit(evaluate[j])&&evaluate[j]!='.')break;
                                    tutu[mama++]=evaluate[j];
                                }
                                tutu[mama]=0;
                                strrev(tutu);
                                i=j+1;
                                if(ans!=0||atof(tutu)!=0)ans=pow(atof(tutu),ans);
                                else {jhamela=1;break;}
                                //cout<<ans<<endl;
                                //cout<<evaluate<<endl;
                            }
                        }

                        for(j=0;j<i;j++)
                            stri[j]=evaluate[j];
                        //strcpy(evaluate,matha);
                        //ans=expression(&evaluate[i+2],0);
                        //cout<<ans<<endl;
                        if(tutut==1){memset(matha,0,sizeof matha);
                        strcat(matha,"(");}
                        sprintf(hayre,"%.09lf",ans);
                        if(tutut==1)
                        {
                            strcat(matha,hayre);
                            strcat(matha,")");
                        }
                        //cout<<hayre<<" :3"<<endl;
                        //cout<<itoa((int)ans,w,10)<<endl;
                        //cout<<w<<endl;
                        for(k=0;k<strlen(hayre)&&tutut==0;k++)
                            stri[j++]=hayre[k];
                        for(k=0;k<strlen(matha)&&tutut==1;k++)
                            stri[j++]=matha[k];
                        //cout<<"MIU"<<endl;
                        //else strcat(str,w);
                        //cout<<str<<"lolo"<<endl;
                        strcat(stri,ptr);
                        memset(evaluate,0,sizeof evaluate);
                        strcpy(evaluate,stri);
                        i=strlen(evaluate);
                        //cout<<i<<" uff"<<endl;
                        //cout<<evaluate<<" hmm"<<endl;
                        //printf("-_-\n");printf("-_-\n");
                        ptr=NULL;
                        tutut=0;
                    }

                    //printf("-_-\n");
                }
                memset(uttor,0,sizeof uttor);
                strcpy(uttor,evaluate);
                memset(evaluate,0,sizeof evaluate);
            }

            else
            {
                char *arr1=strtok(evaluate,"%");
                char *arr2=strtok(NULL,"%");
                if(atoi(arr2)!=0)sprintf(uttor,"%d",atoi(arr1)%atoi(arr2));
                else jhamela=1;
            }
            if(jhamela==1||strcmp(uttor,"1.#INF00000")==0)strcpy(uttor,"Math error");
            jhamela=0;
            vagshesh=0;
        }
    }
}

void iSpecialKeyboard(unsigned char key)
{

}


int main()
{


    //iSetTimer(500,setup);
    iInitialize(700,700,"CALCULATOR");
    getch();
    return 0;
}
