#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char val) {
        data = val;
        left = right = NULL;
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isOperand(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int precedence(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If operand, add to postfix
        if (isOperand(c)) {
            postfix += c;
        }
        // If '(' push to stack
        else if (c == '(') {
            st.push(c);
        }
        // If ')' pop until '('
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
        // If operator
        else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

Node* constructTree(string postfix) {
    stack<Node*> st;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (!isOperator(c)) {
            st.push(new Node(c));
        } else {
            Node* right = st.top(); st.pop();
            Node* left  = st.top(); st.pop();
            Node* newNode = new Node(c);
            newNode->left  = left;
            newNode->right = right;
            st.push(newNode);
        }
    }
    return st.top();
}

void printTree(Node* root, string indent, bool isRight) {
    if (root == NULL) return;
    cout << indent;
    if (isRight) {
        cout << "R----";
        indent += "     ";
    } else {
        cout << "L----";
        indent += "|    ";
    }
    cout << root->data << endl;
    printTree(root->left,  indent, false);
    printTree(root->right, indent, true);
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data;
    }
}


int main() {
    string infix;

    cout << "==============================" << endl;
    cout << "   SYNTAX TREE BUILDER" << endl;
    cout << "==============================" << endl;
    cout << "\nEnter Infix Expression: ";
    cin >> infix;

    // Step 1: Convert infix to postfix
    string postfix = infixToPostfix(infix);
    cout << "\nConverted Postfix : " << postfix << endl;

    // Step 2: Build tree
    Node* root = constructTree(postfix);

    // Step 3: Print visual tree
    cout << "\n--- Visual Tree ---\n" << endl;
    cout << "      " << root->data << endl;
    printTree(root->left,  "      ", false);
    printTree(root->right, "      ", true);

    // Step 4: Traversals
    cout << "\n--- Traversals ---" << endl;
    cout << "Inorder   : "; inorder(root);   cout << endl;
    cout << "Preorder  : "; preorder(root);  cout << endl;
    cout << "Postorder : "; postorder(root); cout << endl;

    cout << "\n==============================" << endl;
    system("pause");
    return 0;
}