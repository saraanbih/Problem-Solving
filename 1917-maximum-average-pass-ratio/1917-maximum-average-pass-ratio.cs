using System;
using System.Collections.Generic;

public class Solution {
    private static double Gain(int p, int t) {
        return (double)(t - p) / ((double)t * (t + 1));
    }

    public double MaxAverageRatio(int[][] classes, int extraStudents) {
        int n = classes.Length;
        double sum = 0.0;

       
        var pq = new PriorityQueue<(int p,int t), double>();

        foreach (var c in classes) {
            int p = c[0], t = c[1];
            sum += (double)p / t;
            pq.Enqueue((p, t), -Gain(p, t));
        }

        while (extraStudents-- > 0) {
            var (p, t) = pq.Dequeue();
            double g = Gain(p, t);   
            sum += g;
            p++; t++;
            pq.Enqueue((p, t), -Gain(p, t));
        }

        return sum / n;
    }
}
