#include <vector>
#include <queue>

using namespace std;

class Graf
{

	protected:
	
		int numarNoduri;
		int numarMuchii;
		vector< vector<int> > data;

		void dfs(const int& v, const int& parent, vector<bool>& visited, vector<int>& ret);
	

	
	public:

		virtual void adaugaMuchie(const int&x, const int& y);

	//	friend istream& operator >> (istream& in, Graf& G);
	
		vector<int> dfs(const int& root);

		vector<int> bfs(const int& root);

};