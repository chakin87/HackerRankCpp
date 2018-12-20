#include <iostream>
#include <algorithm>
#include <string>
#include <vector>



class Message {
public:
	Message() {}
	const std::string& get_text() {
		return m_message;
	}
	void create_message(std::string msg, size_t count) {
		m_message = msg; m_msg_id = count;
	}
	size_t get_id() { return m_msg_id; }
	void set_id(size_t id)  {m_msg_id = id; }

	bool operator < (Message &m){
		if (m_msg_id < m.get_id()){
			return true;
		}
		return false;
	}

private:
	std::string m_message;
	size_t m_msg_id;

};

class MessageFactory {
public:
	MessageFactory() : m_count(0) {}
	Message create_message(const std::string& text) {
		Message m;
		m.create_message(text, m_count);
		++m_count;
		return m;
	}
private:
	size_t m_count;
};

class Recipient {
public:
	Recipient() {}
	void receive(const Message& msg) {
		messages_.push_back(msg);
	}
	void print_messages() {
		fix_order();
		for (auto& msg : messages_) {
			std::cout << msg.get_text() << std::endl;
		}
		messages_.clear();
	}
private:
	void fix_order() {
		std::sort(messages_.begin(), messages_.end());
	}
	std::vector<Message> messages_;
};

class Network {
public:
	static void send_messages(std::vector<Message> messages, Recipient& recipient) {
		// simulates the unpredictable network, where sent messages might arrive in unspecified order
		std::random_shuffle(messages.begin(), messages.end());
		for (auto msg : messages) {
			recipient.receive(msg);
		}
	}
};



int main() {
	MessageFactory message_factory;
	Recipient recipient;
	std::vector<Message> messages;
	std::string text;
	while (std::getline(std::cin, text)) {
		messages.push_back(message_factory.create_message(text));
	}
	Network::send_messages(messages, recipient);
	recipient.print_messages();
	return 0;
}
