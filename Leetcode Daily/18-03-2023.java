import java.util.*;

class BrowserHistory {
    Stack<String> history;
    Stack<String> forward;
    public BrowserHistory(String homepage) {
        history = new Stack<>();
        history.add(homepage);
        forward = new Stack<>();
    }
    
    public void visit(String url) {
        history.add(url);
        forward.clear();
    }
    
    public String back(int steps) {
        int range = Math.min(steps, history.size()-1);
        for(int i = 0; i < range; i++){
            forward.add(history.pop());
        }
        return history.peek();
    }
    
    public String forward(int steps) {
        int range = Math.min(steps, forward.size());
        for(int i =0; i < range; i++){
            history.add(forward.pop());
        }
        return history.peek();
    }
}