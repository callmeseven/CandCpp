#include <iostream>

using namespace std;

struct City{
    char* cityname; 
    int num;
    };

struct Node{
    struct City city; 
    Node* next; 
    };

Node* create(City* a){
	Node* tempNode = new Node;
	tempNode->city.cityname = a->cityname;
	tempNode->city.num = a->num;
	tempNode->next = NULL;
	//cout << tempNode->city.cityname << endl; //test use
	return tempNode;
}

Node* insert(Node* root, Node* current){
	if(root == NULL) return current; 


	if(root->city.num <= current->city.num){
		current->next = root;
		return current;
	}

	else if(root->city.num > current->city.num){
		root->next = insert(root->next, current);
		return root;
	}
}


void printList(Node* node){
	while(node->next != NULL){
	cout << node->city.cityname << " ";
	node = node->next;
	}
	cout << node->city.cityname << endl;
}


void removeSmall(Node* node){
	while(node->next->next != NULL){
		node = node->next;
	}
	free(node->next); 
	node->next = NULL; 
}

//main function
int main()
{
    City a[10];
    int i;
    cout << "Please input some cities." << endl;
    for (i = 0;  ;++i){
		a[i].cityname = new char[30]; 
        cin >> a[i].cityname;
        if (*a[i].cityname == '@') break; 
        cin >> a[i].num;
    }

    Node* root = create(&a[0]);	


    for(int j = 1; j<i; j++){ 

    	Node* temp = create(&a[j]);	

    	root = insert(root, temp);  
    }

    removeSmall(root);

    printList(root);

    return 0;
}
