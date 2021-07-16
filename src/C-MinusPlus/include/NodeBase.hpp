#ifndef nodebase_hpp
#define nodebase_hpp

#include <vector>
#include <string>
#include <iostream>
#include <fstream>



class NodeBase;
extern NodeBase* cur_node;
typedef NodeBase* NodeBasePtr;

typedef std::vector<NodeBasePtr> NodeBaseList;
typedef NodeBaseList* NodeBaseListPtr;

class NodeBase
{
  public:
	virtual ~NodeBase();

	// Visualizer Part
	void printTree(int scopeDepth = 0) const;
	void writeDot(std::string filePath = "./vis/ast.dot") const;
	std::string generateID() const;
	virtual std::string generateLabel() const;
	void generateGraph(std::ostream &os) const;

	//semantic part
	// virtual bool genSymbol();
    virtual bool analysis();
    virtual void predict() {};

	// Generate P Code
	void writeAsm();
	virtual void genPcode();
    //virtual std::string genPcode() const;

	// output C-code
    virtual std::string code() const {}; //prints c90 code so we can compare against input code //called in << overload

    // branch on the trees
    std::vector<NodeBasePtr> childrens;

    // position in the original code
    int col, line;
    void setpos(int x, int y) {
        col = x;
        line = y;
    }

};



#endif
