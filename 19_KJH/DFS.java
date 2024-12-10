/*  Algorithm : DFS
*   Tag : Graph, Graph theory, Graph Search, Backtracking
*   Problem : Baekjoon, No. 1987
*   URL : https://www.acmicpc.net/problem/1987
*/

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	static boolean visited[];
	static int graph[][];
	static int dx[] = { -1, 1, 0, 0 };
	static int dy[] = { 0, 0, -1, 1 };
	static int result = 1;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int R = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
		graph = new int[R][C];
		visited = new boolean[26];
				
		for (int i = 0; i < R; i++) {
			String temp = br.readLine();
			for (int j = 0; j < C; j++) {
				graph[i][j] = temp.charAt(j) - 'A';
			}
		}
		
		DFS(0, 0, 0);
		
		bw.write(result + "\n");
		bw.flush();
		bw.close();
	}
	
	public static void DFS(int x, int y, int cnt) {
		if (visited[graph[x][y]]) {
			result = Math.max(result, cnt);
			return;
		}
		
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			
			if (nextX >= 0 && nextY >= 0 && nextX < graph.length && nextY < graph[0].length) {
				visited[graph[x][y]] = true;
				DFS(nextX, nextY, cnt + 1);
			}
			
			visited[graph[x][y]] = false;
		}
	}
}