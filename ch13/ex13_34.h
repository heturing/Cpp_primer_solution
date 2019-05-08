#include <iostream>
#include <set>

using namespace std;

class Folder;

class Message{
friend class Folder;
friend void swap(Message &, Message &);
public:
	explicit Message(const string &str = "") : contents(str) {}
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();

	void save(Folder&); //Save this msg into a folder.
	void remove(Folder&); //Remove this msg from a folder.

	void addFldr(Folder*);
	void remFldr(Folder*);
private:
	string contents;
	set<Folder*> folders;
	void add_to_Folders(const Message&); //Add this msg to each folder of para's folders.
	void remove_from_Folders(); //Remove this msg from every folder that holds it.
}; 

class Folder{
public:
	Folder() = default;

	void addMsg(Message*);
	void remMsg(Message*);
private:
	set<Message*> msgs;
};

void swap(Message&, Message&);

