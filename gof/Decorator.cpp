#include <iostream>

using namespace std;

/* Component (should be light) */
class Stream {
  public:
    virtual void handleBufferFull() = 0;
    virtual ~Stream(){}
};

class FileStream: public Stream {
  public:
    void handleBufferFull() { cout << "write stream to disk.\n"; }
    ~FileStream() { cout << "FileStream dtor" << '\n'; }
};

class MemoryStream: public Stream {
  public:
    void handleBufferFull() { cout << "increase the buffer size.\n"; }
    ~MemoryStream() { cout << "MemoryStream dtor" << '\n'; }
};

class StreamDecorator : public Stream {
  private:
    Stream *wrappee;
  public:
    void handleBufferFull() { wrappee->handleBufferFull(); }
    StreamDecorator(Stream *s) : wrappee(s) {}
    ~StreamDecorator() { delete wrappee; }
};


class CompressingStream: public StreamDecorator {
  public:
    void handleBufferFull() {
        cout << "Compressing Stream. \n ";
        StreamDecorator::handleBufferFull();
    }
    CompressingStream(Stream *s): StreamDecorator(s) {}
    ~CompressingStream() { cout << "CompressingStream dtor\n"; }
};

class ASCII7Stream: public StreamDecorator {
  public:
    void handleBufferFull() {
        cout << "Convert stream to ASCII 7 bit. \n";
        StreamDecorator::handleBufferFull();
    }
    ASCII7Stream(Stream *s): StreamDecorator(s) {}
    ~ASCII7Stream() { cout << "ASCII7Stream dtor\n"; }
};

class CalculateTime: public StreamDecorator {
  private:
    int elapsedTime;
  public:
    void handleBufferFull() {
        cout << "start time. \n";
        StreamDecorator::handleBufferFull();
        cout << "end time. \n";
    }
    CalculateTime(Stream *s): StreamDecorator(s), elapsedTime(0) {}
    ~CalculateTime() { cout << "CalculateTime dtor\n"; }
};

int main() { 
  Stream *stream = new CalculateTime(new ASCII7Stream(new CompressingStream(new FileStream)));

  stream->handleBufferFull();

  cout<<"\n handleBufferFull DONE \n";

  delete stream;
}