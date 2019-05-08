#include "ex13_34.h"

void Message::save(Folder &f){
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f){
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m){
	for(auto f : m.folders){
		f->addMsg(this);
	}
}

void Message::remove_from_Folders(){
	for(auto f : folders){
		f->remMsg(this);
	}
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders){
	add_to_Folders(m);
}

Message::~Message(){
	remove_from_Folders();		
}

Message& Message::operator=(const Message &m){
	remove_from_Folders();
	contents = m.contents;
	folders = m.folders;
	add_to_Folders(m);
	return *this;
}

inline void Message::addFldr(Folder *f){
	folders.insert(f);
}

inline void Message::remFldr(Folder *f){
	folders.erase(f);
}

void swap(Message &m1, Message &m2){
	using std::swap;
	for(auto f : m1.folders){
		f->remMsg(&m1);
	}
	for(auto f : m2.folders){
		f->remMsg(&m2);
	}

	swap(m1.contents, m2.contents);
	swap(m1.folders, m2.folders);

	for(auto f : m1.folders){
		f->addMsg(&m1);
	}
	for(auto f : m2.folders){
		f->addMsg(&m2);
	}
}

inline void Folder::addMsg(Message *m){
	msgs.insert(m);
}

inline void Folder::remMsg(Message *m){
	msgs.erase(m);
}


