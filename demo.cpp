/**
 * @author: wilbur.ma@foxmail.com
 * @date: 2013-10-25
 * @brief: demo usage of protobuf
 */
#include "news.pb.h"
#include <iostream>
using namespace std;
using namespace test::proto;

void parse_news(NewsStruct *news) {
    const NewsHead &head = news->head();
    cout << "[head] channel_id: " << head.channel_id() << endl;

    int recordNum = news->record_size();
    for(int i = 0; i < recordNum; ++i) {
        const NewsRecord &record = news->record(i);
        cout << "[record " << i << "] title: " << record.title() << endl;
    }
}

void generate_news(NewsStruct *news) {
    NewsHead *head = news->mutable_head();
    head->set_channel_id(250);

    for(int i = 0; i < 5; ++i) {
        NewsRecord *record = news->add_record();
        record->set_title("你好，世界");
    }
}

int main() {
    NewsStruct news;
    generate_news(&news);
    parse_news(&news);
}

