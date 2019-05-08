#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct destination{
	destination() = default;
	destination(string name, int i) : destination_name(name), destination_index(i) {}
	string destination_name = "";
	int destination_index = 0;
};
struct connection{
	connection() = default;
	connection(string name, int i) : connection_name(name), connection_index(i) {}
	string connection_name = "";
	int connection_index = 0;
};

connection connect(destination* d){
	shared_ptr<connection> p(new connection(d->destination_name, d->destination_index));
	cout << "connection's use count is " << p.use_count() << endl;
	return *p;
}

void disconnect(connection c){
	cout << "connection close " << c.connection_name << " " << c.connection_index << endl;
}
void end_connection(connection *p){ disconnect(*p);}

void f(destination &d){
	connection c = connect(&d);
	shared_ptr<connection> p(&c, [] (connection *con) -> void {disconnect(*con);});
	cout << "now connection's use count is " << p.use_count() << endl;
}


int main(){
	string s = "192.168.0.1";
	int i = 100;
	destination des(s,i);
	f(des);
	return 0;
}
