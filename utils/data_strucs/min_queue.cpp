/***** BEGIN MIN_QUEUE *****/

deque<int> mq;
void _remove(int elem){
    if (!mq.empty() && mq.front() == elem) mq.pop_front();
}

void _push(int elem){
    while (!mq.empty() && mq.back() > elem) mq.pop_back();
    mq.push_back(elem);
}

int _front() {
    return mq.front();
}

/***** END MIN_QUEUE *****/
