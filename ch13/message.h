#ifndef MESSAGE
#define MESSAGE
#include <iostream>
#include <set>

class Folder;

class Message{
friend class Folder;
friend void swap(Message &, Message &);
public:
	explicit Message(const std::string &str = "") : contents(str) {}
	Message(const Message&);
	Message& operator=(const Message&);
	Message(Message &&);
	Message& operator=(Message &&m);
	~Message();

	void save(Folder&); //Save this msg into a folder.
	void remove(Folder&); //Remove this msg from a folder.

	void addFldr(Folder*);
	void remFldr(Folder*);
private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_Folders(const Message&); //Add this msg to each folder of para's folders.
	void remove_from_Folders(); //Remove this msg from every folder that holds it.
	void move_Folders(Message *m);

}; 

class Folder{
public:
	Folder() = default;

	void addMsg(Message*);
	void remMsg(Message*);
private:
	std::set<Message*> msgs;
};

void swap(Message&, Message&);

#endif
