/*  Algorithm : BFS
*   Tag : Graph, Graph theory, Graph Search
*   Problem : Baekjoon, No. 10026
*   URL : https://www.acmicpc.net/problem/10026
*/

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	static char graph[][];
	static boolean visited[][];
	static int dx[] = { -1, 1, 0, 0 };
	static int dy[] = { 0, 0, -1, 1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int N = Integer.parseInt(br.readLine());
		int cnt = 0;
		
		graph = new char[N][N];
		visited = new boolean[N][N];
		
		for (int i = 0; i < N; i++) {
			String temp = br.readLine();
			for (int j = 0; j < N; j++) {
				graph[i][j] = temp.charAt(j);
			}
		}
		
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (!visited[j][k]) {
					BFS(j, k, graph, visited);
					cnt++;
				}
			}
		}
		
		bw.write(cnt + " ");
		cnt = 0;
		
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				graph[j][k] = (graph[j][k] == 'R')? 'G' : graph[j][k];
			}
		}
		
		visited = new boolean[N][N];
		
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (!visited[j][k]) {
					BFS(j, k, graph, visited);
					cnt++;
				}
			}
		}
		
		bw.write(cnt + "\n");
		bw.flush();
		bw.close();
	}

	public static void BFS(int x, int y, char graph[][], boolean visited[][]) {
		Queue<int[]> q = new LinkedList<int[]>();
		
		q.add(new int[] { x, y });
		char origin = graph[x][y];
		
		while (!q.isEmpty()) {
			int crt[] = q.poll();
			int nowX = crt[0];
			int nowY = crt[1];
			
			for (int i = 0; i < 4; i++) {
				int nextX = nowX + dx[i];
				int nextY = nowY + dy[i];	
				
				if (nextX < 0 || nextY < 0 || nextX >= graph.length || nextY >= graph[0].length || visited[nextX][nextY] || graph[nextX][nextY] == 0 || origin != graph[nextX][nextY]) {
					continue;
				}
				
				visited[nextX][nextY] = true;
				q.add(new int[] { nextX, nextY });
			}
		}
	}
}