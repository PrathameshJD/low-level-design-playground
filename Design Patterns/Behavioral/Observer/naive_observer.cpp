#include <iostream>
#include <string>

using namespace std;

// Concrete Observer 1
class MobileSubscriber
{
public:
    void notify(const string& videoTitle)
    {
        cout << "Mobile: New video uploaded -> "
             << videoTitle << endl;
    }
};

// Concrete Observer 2
class EmailSubscriber
{
public:
    void notify(const string& videoTitle)
    {
        cout << "Email: New video uploaded -> "
             << videoTitle << endl;
    }
};

// Concrete Observer 3
class TVSubscriber
{
public:
    void notify(const string& videoTitle)
    {
        cout << "TV: New video uploaded -> "
             << videoTitle << endl;
    }
};

// Subject
class YouTubeChannel
{
private:
    MobileSubscriber mobile;
    EmailSubscriber email;
    TVSubscriber tv;

public:
    void uploadVideo(const string& title)
    {
        cout << "\nUploading: " << title << endl;

        // Directly notifying every observer
        mobile.notify(title);
        email.notify(title);
        tv.notify(title);
    }
};

int main()
{
    YouTubeChannel channel;

    channel.uploadVideo("Observer Design Pattern");
    channel.uploadVideo("Strategy Design Pattern");

    return 0;
}