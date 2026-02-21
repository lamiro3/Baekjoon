#include <iostream>
#include <vector>

using namespace std;

class Node {
	public:
		int n;
		vector<Node*> childs;
		Node* parent;

		Node(int v) {
			n = v;
			childs = {};
		}
};

class Tree {
	public:
		Node* root;

		Tree(int r) {
			root = new Node(r);
			root->parent = nullptr;
		}

		Node* find(Node* cur, int n) {
			if (cur == nullptr)
				return nullptr;

			if (cur->n == n)
				return cur;

			for (Node* child : cur->childs) {
				Node* temp = find(child, n);
				if (temp != nullptr)
					return temp;
			}

			return nullptr;
		}

		void insert(int parent, int tgt) {
			Node* newNode = new Node(tgt);

			// root에 삽입할 경우
			if (parent == root->n) {
				newNode->parent = root;
				root->childs.push_back(newNode);
				return;
			}

			// 삽입할 부모 노드 탐색
			Node* f = find(root, parent);
			f->childs.push_back(newNode);
			newNode->parent = f;
		}

		void remove(int tgt) {
			Node* f = find(root, tgt);
			
			if (f == nullptr)
				return;

			if (f == root) {
				delete root;
				root = nullptr;
				return;
			}

			// 삭제할 노드의 자식들을 부모에게 연결
			//for (Node* child : f->childs) {
			//	f->parent->childs.push_back(child);
			//	child->parent = f->parent;
			//}

			auto& siblings = f->parent->childs;

			// 부모의 자식 목록에서 본인을 삭제
			for (int i = 0; i < siblings.size(); i++) {
				if (siblings[i] == f) {
					siblings.erase(siblings.begin() + i);
					break;
				}
			}

			delete f;
		}

		int cntLeaf(Node* cur) {
			if (cur == nullptr)
				return 0;

			if (cur->childs.size() == 0)
				return 1;

			int sum = 0;

			for (Node* child : cur->childs) {
				sum += cntLeaf(child);
			}

			return sum;
		}
};

int main() {
	int N, tgt;
	cin >> N;

	Tree* tree = nullptr;

	for(int n=0; n<N; n++) {
		int parent;
		cin >> parent;

		if (parent == -1)
			tree = new Tree(n);

		else
			tree->insert(parent, n);
	}

	cin >> tgt;

	if (tree != nullptr) {
		tree->remove(tgt);
		cout << tree->cntLeaf(tree->root);
	}
	return 0;
}