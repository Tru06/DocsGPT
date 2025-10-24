#include &lt;iostream&gt;
#include &lt;cctype&gt;
#include &lt;string&gt;
using namespace std;

// Node definition for singly linked list
struct Node {
char data;
Node* next;
Node(char value) : data(value), next(NULL) {} // Constructor for Node
};

// Stack ADT using singly linked list
class Stack {
Node* topNode;

public:
Stack() : topNode(NULL) {}

void push(char value) {
Node* newNode = new Node(value); // Use constructor
newNode-&gt;next = topNode;
topNode = newNode;
}
,,.
char pop() {
if (isEmpty()) return &#39;\0&#39;;
Node* temp = topNode;
char value = temp-&gt;data;
topNode = topNode-&gt;next;
delete temp;

return value;
}

char top() {
return (topNode) ? topNode-&gt;data : &#39;\0&#39;;
}

bool isEmpty() {
return topNode == NULL;
}
};

// Function to check precedence of operators
int precedence(char op) {
if (op == &#39;+&#39; || op == &#39;-&#39;) return 1;
if (op == &#39;*&#39; || op == &#39;/&#39;) return 2;
return 0;
}

// Infix to Postfix conversion
string infixToPostfix(const string&amp; infix) {
Stack s;
string postfix;

for (size_t i = 0; i &lt; infix.length(); ++i) {
char ch = infix[i];
if (isalnum(ch)) {
postfix += ch; // Append operand to result
} else if (ch == &#39;(&#39;) {
s.push(ch);
} else if (ch == &#39;)&#39;) {

while (s.top() != &#39;(&#39;) postfix += s.pop();
s.pop(); // Remove &#39;(&#39;
} else {
while (!s.isEmpty() &amp;&amp; precedence(s.top()) &gt;= precedence(ch))
postfix += s.pop();
s.push(ch);
}
}

while (!s.isEmpty()) {
postfix += s.pop(); // Pop remaining operators
}

return postfix;
}

// Infix to Prefix conversion
string infixToPrefix(const string&amp; infix) {
Stack operators;
string result;

// Reverse traversal for prefix conversion
for (int i = infix.length() - 1; i &gt;= 0; --i) {
char ch = infix[i];

if (isalnum(ch)) {
result = ch + result; // Operand goes to result
} else if (ch == &#39;)&#39;) {
operators.push(ch);
} else if (ch == &#39;(&#39;) {
while (operators.top() != &#39;)&#39;)

result = operators.pop() + result;
operators.pop(); // Remove &#39;)&#39;
} else {
while (!operators.isEmpty() &amp;&amp; precedence(operators.top()) &gt; precedence(ch))
result = operators.pop() + result;
operators.push(ch);
}
}

while (!operators.isEmpty()) {
result = operators.pop() + result; // Pop remaining operators
}

return result;
}

int main() {
string infix;
cout &lt;&lt; &quot;Enter an infix expression: &quot;;
cin &gt;&gt; infix;

// Postfix Conversion
string postfix = infixToPostfix(infix);
cout &lt;&lt; &quot;Postfix Expression: &quot; &lt;&lt; postfix &lt;&lt; endl;

// Prefix Conversion
string prefix = infixToPrefix(infix);
cout &lt;&lt; &quot;Prefix Expression: &quot; &lt;&lt; prefix &lt;&lt; endl;

return 0;
}
