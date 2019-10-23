struct SegmentTree {
   int n;
   vector <int> tree;
   vector <int> data;

   void build(int node, int start, int end)
   {
       if(start == end)
       {
           tree[node] = data[start];
       }
       else
       {
           int mid = (start + end) / 2;
           build(2*node, start, mid);
           build(2*node+1, mid+1, end);
           tree[node] = tree[2*node] + tree[2*node+1];
       }
   }

   SegmentTree(vector <int> data) {
         this->n = sz(data);
         this->data = data;
         tree.assign(3*sz(data) + 1, 0);
         build(1,0,sz(data)-1);
   }

   void update(int node, int start, int end, int idx, int val)
   {
       if(start == end)
       {
         tree[node] += val;
       }
       else
       {
           int mid = (start + end) / 2;
           if(start <= idx and idx <= mid)
           {
               update(2*node, start, mid, idx, val);
           }
           else
           {
               update(2*node+1, mid+1, end, idx, val);
           }
           tree[node] = tree[2*node] + tree[2*node+1];
       }
   }
   int query(int node, int start, int end, int l, int r)
   {
       if(r < start or end < l)
       {
           return 0;
       }
       if(l <= start and end <= r)
       {
           return tree[node];
       }
       int mid = (start + end) / 2;
       int p1 = query(2*node, start, mid, l, r);
       int p2 = query(2*node+1, mid+1, end, l, r);
       return (p1 + p2);
   }
 };
