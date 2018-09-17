import java.io.*;
import java.util.*;


public class GopherandHawks {
	static double distance;
	static int INF = (int) 1e9;
	static ArrayList<ArrayList<Integer>> graph;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer  stk;
		ArrayList<Point> points;
		while(true) {
			String line = br.readLine().trim();
			if(line==null)break;
			stk = new StringTokenizer(line);
			int v = Integer.parseInt(stk.nextToken());
			int t = Integer.parseInt(stk.nextToken());
			if(v+t==0)break;
			distance  = v*t*60.0;
			points = new ArrayList<>();
			while(true) {
				line = br.readLine().trim();
				if(line.isEmpty())break;
				stk = new StringTokenizer(line);
				points.add(new Point(Double.parseDouble(stk.nextToken()),Double.parseDouble(stk.nextToken())));
				points.get(points.size()-1).print();;
			}
			graph = new ArrayList<>();
			for (int i = 0; i < points.size(); i++) {
				graph.add(new ArrayList<>());	
			}
			System.err.println(distance);
			for (int i = 0; i < points.size(); i++) {
				for (int j = i+1; j < points.size(); j++) {
					System.err.println(i+ " " + j + " " + points.get(i).dist(points.get(j)));
					if(points.get(i).dist(points.get(j))>distance) {
						graph.get(i).add(j);
						graph.get(j).add(i);
					}
				}
			}
			System.err.println(graph.size());
			int res = bfs();
			System.out.println((res==0)?"No." : String.format("Yes, visiting %d other holes",res));
			
		}
		
	}
	
	static int bfs() {
		ArrayDeque<Integer> q = new ArrayDeque<>();
		int dis[] = new int[graph.size()+1];
		q.push(0);
		Arrays.fill(dis,INF);
		dis[0] = 0;
		while(!q.isEmpty()) {
			int u = q.pollFirst();
			System.err.println(u + " " + dis[u]);
			if(u==1)return dis[1];
			for(int v : graph.get(u)) {
				if(dis[v]==INF) {
					dis[v] = dis[u]+ 1;
					q.push(v);
				}
			}
		}
		return 0;
	}
	
}

class Point{
	
	static double x,y;
	public Point(double x, double y) {
		this.x = x;
		this.y = y;
	}
	
	public double dist(Point other) {
		return Math.sqrt(Math.pow(other.x-this.x,2.) + Math.pow(other.y-this.y,2.) );
	}
	
	public void print(){
		System.err.println("("+x+","+y+")");
	}
		
}
