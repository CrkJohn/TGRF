import java.io.*;
import java.util.*;


public class Main{
	static double distance;
	static int INF = (int) 1e9;

	static ArrayList<Double> xCor;
	static ArrayList<Double> yCor;
	static ArrayList<ArrayList<Integer>> graph;
	public static void main(String[] args) throws IOException {
		FileInputStream instream = new FileInputStream("src/in.txt");  
		BufferedReader br = new BufferedReader(new InputStreamReader(instream));
		StringTokenizer  stk;
		int ntc = 0;
		while(true) {
			String line = br.readLine().trim();
			ntc++;
			if(line==null)break;
			stk = new StringTokenizer(line);
			Double v = Double.parseDouble(stk.nextToken());
			Double t = Double.parseDouble(stk.nextToken());
			if(v+t==0)break;
			distance  = v*t*60.0;
			xCor= new ArrayList<>();
			yCor= new ArrayList<>();
			while(true) {
				line = br.readLine().trim();
				if(line.isEmpty())break;
				stk = new StringTokenizer(line);
				Double x = Double.parseDouble(stk.nextToken());
				Double y = Double.parseDouble(stk.nextToken());
				xCor.add(x);
				yCor.add(y);
			}
		
			graph = new ArrayList<>();
			for (int i = 0; i < xCor.size(); i++) {
				graph.add(new ArrayList<>());	
			}
			for (int i = 0; i < xCor.size(); i++) {
				for (int j = i+1; j < xCor.size(); j++) {
					double disntanceTMP = dist(xCor.get(i),xCor.get(j),yCor.get(i),yCor.get(j));
					if(disntanceTMP<=distance) {
						graph.get(i).add(j);
						graph.get(j).add(i);
					}
				}
			}
			long  res = bfs();
			System.out.println((res==-1)?"No." : String.format("Yes, visiting %d other holes.",res));
			
		}
		
	}
	
	static long bfs() {
		ArrayDeque<Integer> q = new ArrayDeque<>();
		long dis[] = new long[graph.size()+1];
		q.push(0);
		Arrays.fill(dis,INF);
		dis[0] = 0;
		while(!q.isEmpty()) {
			int u = q.pollFirst();
			for(int v : graph.get(u)) {
				if(dis[v]==INF) {
					if(v==1)return dis[u];
					dis[v] = dis[u]+ 1;
					q.push(v);
				}
			}
		}
		return -1;
	}
	
	public static double dist(Double x1,Double x2,Double y1,Double y2) {
		Double r = (x1-x2)*(x1-x2);
		Double r2 = (y1-y2)*(y1-y2);
		return Math.sqrt(r+r2);
	}
	
}

