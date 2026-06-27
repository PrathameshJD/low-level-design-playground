#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class ISubscriber{
public:
    virtual void update() = 0;
    virtual ~ISubscriber()= default;
};

class IChannel{
public:
    virtual ~IChannel() = default;
    virtual void subscribe(ISubscriber * subscriber)= 0;
    virtual void unSubscribe(ISubscriber * subscriber) = 0;
    virtual void notify() = 0;
};

class Channel : public IChannel{
    vector<ISubscriber*> subscribers;
    string name;
    string title;

public:

    Channel(string name){
        this-> name = name;
    }

void subscribe(ISubscriber * subscriber)override{
    if(find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end()){
        subscribers.push_back(subscriber);
    }
}

void unSubscribe(ISubscriber * subscriber)override{
    auto it =  find(subscribers.begin(), subscribers.end(), subscriber); 
    if(it!= subscribers.end())    
    subscribers.erase(it);
}

void notify()override{
    for(auto subscriber:subscribers){
        subscriber->update();
    }
}

void uploadVideo(string title){
    this->title = title; 
    cout << "Uploaded new video: " << this->title << endl;
    notify();
}

void getVideo(){
    cout << "New Video: " << title << endl;
}

};

class Subscriber : public ISubscriber{
    Channel *channel;

public:
    Subscriber(Channel* channel){
        this->channel=channel;
    }

    void update()override{
        channel->getVideo();
    }
};

int main(){
    Channel *channel1 = new Channel("Preetams Channel");
    Subscriber *sub1 = new Subscriber(channel1);
    channel1->subscribe(sub1);
    channel1->uploadVideo("HEY HEYYYY");

    Subscriber *sub2 = new Subscriber(channel1);
    channel1->subscribe(sub2);
    channel1->uploadVideo("BYE BYEEEEE");


}
