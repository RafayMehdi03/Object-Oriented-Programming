#include <iostream>
#include <string>
using namespace std;

class Message {
private:
    string text;

public:
    string toString() const {  
        return text;
    }

    void setText(const string& newText) {
        text = newText;
    }
};

class SMS : public Message {
private:
    string recipientContactNo;

public:
    void setRecipientContactNo(const string& contactNo) {
        recipientContactNo = contactNo;
    }

    string toString() const {
        return recipientContactNo + ": " + Message::toString();
    }
};

class Email : public Message {
private:
    string sender, receiver, subject;

public:
    void setSender(const string& newSender) {
        sender = newSender;
    }

    void setReceiver(const string& newReceiver) {
        receiver = newReceiver;
    }

    void setSubject(const string& newSubject) {
        subject = newSubject;
    }

    string toString() const {
        return "From: " + sender + " To: " + receiver + " Subject: " + subject + " " + Message::toString();
    }
};

bool ContainsKeyword(const Message& messageObject, const string& keyword) {
    string text = messageObject.toString();  
    return text.find(keyword) != string::npos;
}

string encodeMessage(const string& message) {
    int length = message.length();
    char encodedMessage[length + 1];  
    
    for (int i = 0; i < length; ++i) {
        char c = message[i];
        if (c >= 'A' && c <= 'Z') {
            encodedMessage[i] = (c == 'Z') ? 'A' : c + 1;
        } else if (c >= 'a' && c <= 'z') {
            encodedMessage[i] = (c == 'z') ? 'a' : c + 1;
        } else {
            encodedMessage[i] = c; 
        }
    }
    
    encodedMessage[length] = '\0';  
    return string(encodedMessage);
}

int main() {
    SMS sms;
    sms.setText("Hello, this is a test SMS");
    sms.setRecipientContactNo("1234567890");

    Email email;
    email.setText("This is an email message");
    email.setSender("sender@example.com");
    email.setReceiver("receiver@example.com");
    email.setSubject("Test Subject");

    cout << "SMS: " << sms.toString() << endl;
    cout << "Email: " << email.toString() << endl;

    cout << "Contains 'test' in SMS: " << ContainsKeyword(sms, "test") << endl;
    cout << "Contains 'email' in Email: " << ContainsKeyword(email, "email") << endl;

    cout << "Encoded message: " << encodeMessage("This is Java") << endl;

    return 0;
}