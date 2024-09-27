// Goal: Check whether can i add an event into a calander that will not cause a
// triple booking Intuition: just check through the interval where there exists
// a double booking have 2 event list 1 will be non overlapping intervals 1 will
// be overlapping intervals for each event just check whether does it overlap
// with the overlapping intervals if it doesnt overlap we will have to update
// the non_overlapping event to check whether does it overlapping with any other
// event that causes double booking.

// Time Complexity: O(n) because we just go through the list
// Space Complexity: O(n)
class MyCalendarTwo {
public:
  std::vector<std::pair<int, int>> non_overlapping;
  std::vector<std::pair<int, int>> overlapping;

  MyCalendarTwo() {}

  bool book(int start, int end) {
    // check whether does it happen for triple booking by checking it with the
    // overlapping list (double booking)
    for (const auto &[s, e] : overlapping)
      if (end > s && start < e)
        return false;

    // no triple booking then add into the list for both overlapping and non
    // overlapping
    for (const auto &[s, e] : non_overlapping)
      if (s < end && start < e)
        overlapping.emplace_back(std::max(s, start), std::min(end, e));
    non_overlapping.emplace_back(start, end);
    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
