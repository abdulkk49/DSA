#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack<int> s1;

bool isNum(char);
bool isOperator(char);
int performOperation(int, int, char);
int prePostEvaluation(int, string);
int preEvaluation(string);
int postEvaluation(string);

bool isNum(char ch){
    return (ch >= '0' && ch <= '9');
}
bool isOperator(char ch){
    return (ch == '+' || ch == '*' || ch == '/' || ch == '-');
}

int performOperation(int operand1, int operand2, char myOperator){
    if(myOperator == '+')
        return operand1 + operand2;
    else if(myOperator == '-')
        return operand1 - operand2;
    else if(myOperator == '*')
        return operand1 * operand2;
    else if(myOperator == '/')
        return operand1 / operand2;
}
int postEvaluation(string str){
    if(!isNum(str[0])){
        cout << "Invalid Postfix..\n";
        return -1;
    }
    
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ',' || str[i] == ' '){
            continue;
        }
        else if(isNum(str[i])){
            int num = str[i] - '0';
            while(i<str.length() && isNum(str[i+1])){
                i+=1;
                num = num*10 + (str[i] - '0');
            }
            s1.push(num);
        }
        else if(isOperator(str[i])){
            int operand2 = s1.top();
            s1.pop();
            int operand1 = s1.top();
            s1.pop();
            int result = performOperation(operand1, operand2, str[i]);
            s1.push(result);
        }
        else if(!isNum(str[i]) && !isOperator(str[i])){
            cout << "Invalid String\n";
            return -1;
        }
    }
    return s1.top();
}

int preEvaluation(string str){
    if(!isNum(str[str.length() - 1])){
        cout << "Invalid Prefix..\n";
        return -1;
    }
    for(int j = str.length()-1; j >= 0; j--){
        if(str[j] == ',' || str[j] == ' '){
            continue;
        }
        else if(isNum(str[j])){
            int num = str[j] - '0';
            int powerOfTen = 10;
            while(j >= 0 && isNum(str[j-1])){
                j-=1;
                
                num = num + (str[j] - '0')*powerOfTen;
                powerOfTen*=10;
            }
            s1.push(num);
        }
        else if(isOperator(str[j])){
            int operand1 = s1.top();
            s1.pop();
            int operand2 = s1.top();
            s1.pop();
            int result = performOperation(operand1, operand2, str[j]);
            s1.push(result);
        }
        else if(!isNum(str[j]) && !isOperator(str[j])){
            cout << "Invalid String\n";
            return -1;
        }
    }
    return s1.top(); 
}

int prePostEvaluation(int flag, string str){
    if(flag == 1){
        return preEvaluation(str);
    }
    return postEvaluation(str);
}

int main(){
    string str;
    int flag;
    cout << "Enter 0 for postfix, 1 for prefix:\n";
    cin >> flag;
    cin.ignore();
    cout << "Enter the String:\n";
    getline(cin, str);

    cout << "Evaluated Value is:\n";
    cout << prePostEvaluation(flag,str)<<endl;;
}
