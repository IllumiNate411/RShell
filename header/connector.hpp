#ifndef __CONNECTOR_HPP__
#define __CONNECTOR_HPP__

using namespace std;

class connector{
	private:

	public:
	connector();

	virtual bool ececute() = 0;
	void sLeft();
	void sRight();
	void gLeft();
	void gRight();

	protected:
	connector* Lside;
	connector* Rside;
};
#endif

