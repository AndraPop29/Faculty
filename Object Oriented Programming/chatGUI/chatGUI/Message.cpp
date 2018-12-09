#include "Message.h"

Message::Message() : text(" "), u(-1) {}

Message::Message(string t, int u)
{
	this->text = t;
	this->u = u;
}


Message::~Message()
{
}
