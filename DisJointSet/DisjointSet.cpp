#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 트리를 이용해 상호 배제적 집합을 구현한다.
struct OptimizedDisjointSet {
	vector<int> parent, rank;

	OptimizedDisjointSet(int n) : parent(n), rank(n, 1) { //초기화
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	// u 가 속한 트리의 루트의 번호를 반환한다
	int find(int u) { //찾기
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	// u 가 속한 트리와 v 가 속한 트리를 합친다
	void merge(int u, int v) { //합치기
		u = find(u); v = find(v);
		// 이미 둘이 같은 트리에 속한 경우
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);
		// 이제 항상 rank[v] 가 더 크므로 u 를 v 의 자식으로 넣는다
		if (rank[u] == rank[v]) rank[v]++;
		parent[u] = v;
	}
};
int main()
{
	OptimizedDisjointSet d(10); //0~9까지의 상호 배타적 집합 만듬.
	d.merge(0, 1); //0과 1은 같은 집합이다.
	d.merge(1, 2); //1과 2는 같은 집합이다.
	d.merge(2, 3); //2와 3은 같은 집합이다. 결국 0,1,2,3은 모두 같은 집합이다.

	cout << "f = " << d.find(0) << endl; //0,1,2,3의 부모를 출력해보면 모두 동일한 부모가 나오는걸 확인할수 있다.
	cout << "f = " << d.find(1) << endl;
	cout << "f = " << d.find(2) << endl;
	cout << "f = " << d.find(3) << endl;
	return 0;
}
