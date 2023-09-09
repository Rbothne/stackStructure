//Robert Bothne
//Homework2 - calculator converting to postfix then solving with stacks.
//2-27-21 - ignore the commented out code, different attempts

#include <iostream>
#include <string>
using namespace std;

#include "linkedstack.h"


string getInput = " ";
string inToPost(string s);
int isFirst(char op1, char op2);
int findPrec(char op);
float evaluation(string s);

int main(){
    LinkedStack<int> operands;
    LinkedStack<char> operators;
    string s = "";
    cout << "please input your infix: ";
    getline(cin,s); //- fails with inputs being white space
    string postfix = inToPost(s);
    cout << "postfix expression: " << postfix;
    float result = evaluation(postfix); //this is just to store the value, no point to assignment
}
string inToPost(string s){
    LinkedStack<char> stack;
    int length = s.length();
    string postfix;
    for(int i = 0; i < length; i++) 
    { 
        if(s[i] == ' ') continue; //due to whitespaces from getline
        else if((s[i] >= '0' && s[i] <= '9')){
             postfix+=s[i]; 
        }
        else if(s[i] == '(') {
            stack.push('(');
        }
        else if(s[i] == ')')
        { 
            while(stack.peek() != '\0' && stack.peek() != '(') 
            { 
                char temp = stack.peek(); 
                stack.pop(); 
                postfix+= temp; 
            } 
            if(stack.peek() == '(') 
            { 
                char temp = stack.peek(); 
                stack.pop(); 
            } 
        }else{ 
            while(stack.peek() != '\0' && isFirst(stack.peek(),s[i])) 
            { 
                char temp = stack.peek(); 
                stack.pop(); 
                postfix+= temp; 
            } 
            stack.push(s[i]); 
        } 
    } 
    while(stack.peek() != '\0') 
    { 
        char temp = stack.peek(); 
        stack.pop(); 
        postfix+= temp; 
    } 
    return postfix;
} 
int isFirst(char op1,char op2){
    int op1Prec = findPrec(op1);
	int op2Prec = findPrec(op2);
	if(op1Prec == op2Prec){
	 return true;
	}
	else if(op1Prec>op2Prec){
        return true;
    }else if(op2Prec>op1Prec){
        return false;
    }else{
        return 3;
    }
}
int findPrec(char op)
{
	int prec = -1; 
	if (op=='+' || op=='-'){
		prec = 1;
    }
    if (op=='*' || op=='/'){
		prec = 2;
    }
    return prec;
}
float evaluation (string s){
    LinkedStack<float> stack2;
    for (int i = 0; s[i] ; i++){
        if((s[i] >= '0' && s[i] <= '9')){
           stack2.push(s[i]-'0');//dropping ascii to numerical value
        }
        else{
            float op1 = stack2.peek();
            stack2.pop();
            float op2 = stack2.peek();
            stack2.pop();
            switch (s[i])  
            {  
            case '+': stack2.push(op2+op1); 
            break;  
            case '-': stack2.push(op2-op1); 
            break;  
            case '*': stack2.push(op2*op1); 
            break;  
            case '/': stack2.push(op2/op1); 
            break;  
            }  
        }
    }
    cout << endl << "The resulting answer is: " << stack2.peek();
    return stack2.peek();
}