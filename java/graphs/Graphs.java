package graphs;
import java.util.*;
public class Graphs {
    private LinkedList<Integer> adj[];

    public Graphs(int v) {
     
        adj = new LinkedList[v];
        for (int i = 0; i < v; i++) {
            adj[i] = new LinkedList<Integer>();
        }
    }

    public void addEdge(int source, int destination) {

        adj[source].add(destination);
        adj[destination].add(source);
    }

    public int bfs(int source, int destination) {

        Queue<Integer> queue = new LinkedList<Integer>();
        int[] parent = new int[adj.length];
        boolean[] visited = new boolean[adj.length];
        visited[source] = true;
        parent[source] = -1;
        queue.add(source);

        while (!queue.isEmpty()) {

            int curr = queue.poll();
            for (int node : adj[curr]) {
                if (!visited[node]) {
                    visited[node] = true;
                    parent[node] = curr;
                    queue.add(node);
                }

            }

        }
        int curr = destination;
        int dist = 0;
        while (parent[curr] != -1) {

            System.out.print(curr + " -> ");
            curr = parent[curr];
            dist++;
        }
        System.out.println(source);
        return dist;

    }

    public boolean dfsRecursionHelper(int source, int destination, boolean visited[]) {

        if (source == destination)
            return true;

        for (int node : adj[source]) {
            if (!visited[node]) {
                visited[node] = true;
                boolean hasPath = dfsRecursionHelper(node, destination, visited);
                if (hasPath)
                    return true;

            }
        }

        return false;
    }

    public void dfsRecursion(int source, int destination) {

        boolean[] visited = new boolean[adj.length];
        visited[source] = true;
        if (dfsRecursionHelper(source, destination, visited)) {
            System.out.println("path exists");
        } else {
            System.out.println("path does not exists");
        }
    }

    public boolean dfsStack(int source, int destination) {
        boolean[] visited = new boolean[adj.length];
        visited[source] = true;
        Stack<Integer> s = new Stack<>();
        s.push(source);
        visited[source] = true;

        while (!s.isEmpty()) {

            int curr = s.pop();
            if (curr == destination) {
                return true;
            }
            for (int node : adj[curr]) {
                if (!visited[node]) {
                    visited[node] = true;
                    s.push(node);
                }
            }

        }
        return false;

    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter number of edges and vertices for graph");
        int v = sc.nextInt();
        int e = sc.nextInt();

        Graphs g = new Graphs(v);
        for (int i = 0; i < e; i++) {
            System.out.println("enter edges");
            int source = sc.nextInt();
            int destination = sc.nextInt();
            g.addEdge(source, destination);
        }

        System.out.println("enter source and destination");
        int source = sc.nextInt();
        int destination = sc.nextInt();
        // System.out.println(g.bfs(source, destination));
        // g.dfsRecursion(source, destination);
        System.out.println(g.dfsStack(source, destination));
        sc.close();
    }

}
