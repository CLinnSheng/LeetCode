// Goal: Check whether can i add an event into a calander
// eg: the booking is on half-open interval [start,end) means the next event can
// be book on the end date
//
// Intuition: have sorted order of event list then check whether this event is
// it in between of any pair of event Time Complexity: O(nlgn) lgn is because of
// every time we trying to find the lower bound and insert Space Complexity:
// O(n)
class MyCalendar {
public:
  std::set<std::pair<int, int>> calender;

  MyCalendar() {}

  bool book(int start, int end) {
    auto event = make_pair(start, end);
    // It will compare the first element first if there are more than 1 or equal
    // first element than proceed by comparing the second element
    auto overlapping_event = calender.lower_bound(event);

    // check the current event
    if (overlapping_event != calender.end() && overlapping_event->first < end)
      return false;
    // check the prev event
    if (overlapping_event != calender.begin()) {
      auto prev_event = prev(overlapping_event);
      if (prev_event->second > start)
        return false;
    }
    calender.insert(event);
    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
