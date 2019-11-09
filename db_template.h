#include <istream>
#include <ostream>
#include <string>  
#include <vector>


class BaseContainer{};

template <typename K, typename D> class Container: public BaseContainer{
private:
	K key;
	D data;

public:
	Container(K key_m, D data_m);

	K get_key();
	D get_data();
};


class BTreeNode{
	public:
		std::vector<unsigned int> children_id;
		std::vector<BaseContainer> keys;
		unsigned int current_children_count;

		BTreeNode();	
	};

class DBManager{
private:
	static DBManager *db_manager;
	std::string db_path;

	void save_btree_node(BTreeNode* node);
	BTreeNode* load_btree_node(unsigned int tree_id);
	DBManager(std::	string data_path);

public:
	static DBManager* get_instance(std::string db_path);
	BTreeNode* get_tree_by_id(unsigned int tree_id);
	unsigned int get_new_btree_node();
};


class BaseCmp{
public:
	virtual bool operator()(BaseContainer c1, BaseContainer c2);
};

class KDCmp: public BaseCmp{
private:
	unsigned int min_tree_degree;
	unsigned int depth;

public:

	bool operator()(BaseContainer c1, BaseContainer c2);
};


class BTree{
private:
	unsigned int root;
	DBManager *db_manager;

public:
	BTree(std::string db_path);

	template <typename Cmp> void add(BaseContainer container);
	template <typename Cmp> void del(BaseContainer container);
	template <typename Cmp> std::vector<BaseContainer> search(BaseContainer container);

	void save(std::ostream out_stream);
};


class DB{
private:
	BTree *b_tree;
	static DB *db;

	DB();

public:
	static DB* get_instance(std::string b_tree_save_path);
	template <typename Cmp> void add(BaseContainer container);
	template <typename Cmp> std::vector<BaseContainer> range_search(std::vector<BaseContainer> l_range, std::vector<BaseContainer> r_range);
	template <typename Cmp> std::vector<BaseContainer> neighbor_search(unsigned int count, BaseContainer container);	

};