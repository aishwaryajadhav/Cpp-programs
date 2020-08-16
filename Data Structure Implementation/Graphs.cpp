#include <bits/stdc++.h> 
using namespace std; 


class Node{
    public:
    int data;
    vector<Node*> neighbours;
    Node(int d):data(d){}
};
class ParentInfo{
    public:
    int level=-1;
    Node* parent=NULL;
    int visited=0;
    ParentInfo(int l, int v, Node* p=NULL):level(l),visited(v),parent(p){}
};
class Graph{
    vector<Node*> nodes;
    void DFS_helper(Node* node, unordered_set<Node*>& us);
    void bfs_helper(Node* node, queue<Node*> &q, unordered_set<Node*>& us);
    void printPath(Node* p, Node* op, unordered_map<Node*, ParentInfo*>& um);
    
    public:
    Node* getNode(int a);
	void DFS();
    void insert(int d);
    void insert(int a, int b, int c);
    void printGraph();
    void BFS();
    void BidirectionalSearch(Node* a, Node* b);
};
Node* Graph::getNode(int a){
    for(auto p:nodes){
        if(p->data==a){
            return p;
        }
    }
    return NULL;   
}
void Graph::insert(int d){
    Node* n=new Node(d);
    nodes.push_back(n);
}
void Graph::insert(int a, int b, int c=0){
    Node* an=getNode(a);
    Node* bn=getNode(b);
    an->neighbours.push_back(bn);
    if(c)
        bn->neighbours.push_back(an);
}
void Graph::printGraph(){
    for(auto p:nodes){
        cout<<endl<<p->data<<": ";
        for(auto q:p->neighbours)
            cout<<q->data<<" ";
    }
}
void Graph::DFS_helper(Node* node, unordered_set<Node*>& us){
    if(us.find(node)!=us.end())
        return;
    us.insert(node);
    cout<<node->data<<" ";
    for(auto n:node->neighbours){
        DFS_helper(n,us);
    }
}
void Graph::DFS(){
    unordered_set<Node*> us;
    for(auto node: nodes){
        DFS_helper(node, us);
    }
}

void Graph::bfs_helper(Node* node, queue<Node*> &q, unordered_set<Node*>& us){
    if(us.find(node)!=us.end())
        return;
    cout<<endl;
    us.insert(node);
    q.push(node);
    while(!q.empty()){
        node=q.front();
        q.pop();
        cout<<node->data<<" ";
        for(auto p:node->neighbours){
            if(us.find(p)==us.end()){
                us.insert(p);
                q.push(p);
            }
        }
    }
}
void Graph::BFS(){
    unordered_set<Node*> us;
    queue<Node*> q;
    for(auto node:nodes){
        
        bfs_helper(node, q,us);
    }
}

void Graph::BidirectionalSearch(Node* a, Node* b){  
    if(a==NULL || b==NULL)
        return;
    if(a==b){
        cout<<a->data<<endl;
        return;
    }
    unordered_map<Node*, ParentInfo*> um;
    queue<Node*> aq;
    queue<Node*> bq;
    aq.push(a);
    bq.push(b);
    ParentInfo* ap=new ParentInfo(0, 1);
    ParentInfo* bp=new ParentInfo(0, 2);
    um[a]=ap;
    um[b]=bp;
    int level=1, countA=1, countB=1;
    while(countA!=0 || countB!=0){
        while(countA!=0){
            a=aq.front(); 
            aq.pop();
            countA--;
            for(auto p:a->neighbours){
                if(um.find(p)==um.end()){
                	ap=new ParentInfo(level, 1,a);
                    um[p]=ap;
                    aq.push(p);
                }
                else if(um[p]->visited == 2){
                    cout<<"Path of length: "<<um[p]->level+level<<" found.\n";
                   	printPath(p,a,um);
                    return;
                }
            }
        }
        countA=aq.size();
        while(countB!=0){
            b=bq.front(); 
            bq.pop();
            countB--;
            for(auto p:b->neighbours){
                if(um.find(p)==um.end()){
                    bp=new ParentInfo(level, 2,b);
                    um[p]=bp;
                    bq.push(p);
                }
                else if(um[p]->visited == 1){
                    cout<<"Path of length: "<<um[p]->level+level<<" found.\n";
                    printPath(p,b,um);
                    return;
                }
            }
        }
        countB=bq.size();
        level++;
    }
    cout<<"No path between the two nodes exists.\n";
}
void Graph::printPath(Node* p, Node* op, unordered_map<Node*, ParentInfo*>& um){
    deque<Node*> dq;
    while(p!=NULL){
        dq.push_back(p);
        p=um[p]->parent;
    }
    while(op!=NULL){
        dq.push_front(op);
        op=um[op]->parent;
    }
    cout<<"Path: ";
    while(!dq.empty()){
        p=dq.front();
        cout<<p->data<<" ";
        dq.pop_front();
    }
}



int main(){
	int n;
	int a,b;
	cin>>n;
	Graph g;
	while(1){
		switch(n){
			case -1: return 0;
			case 1: cin>>a;
			g.insert(a);break;
			case 2: cin>>a>>b;
			g.insert(a,b);break;
			case 3: cin>>a>>b;
			g.insert(a,b,1);break;	//for undirected graph
			case 4:g.printGraph();
			break;
			case 5:g.DFS();break;
			case 6:g.BFS(); break;
			case 7:cin>>a>>b;
			g.BidirectionalSearch(g.getNode(a),g.getNode(b));
		}
		cin>>n;
	}
	return 0;
}



