class SegmentTreeNode {
        public:
        int maxOverlap=0;
        int lazy=0;
        SegmentTreeNode* left=nullptr;
        SegmentTreeNode* right=nullptr;
    };

    class SegmentTree {
        SegmentTreeNode* root;
        public:
        SegmentTree() {
            root= new SegmentTreeNode();
        }

        SegmentTreeNode* getRoot() {
            return root;
        }

        void update(SegmentTreeNode* node,int nodeStart,int nodeEnd,int rangeStart,int rangeEnd) {
            if(!node)return;

            if(rangeStart>=nodeEnd||rangeEnd<=nodeStart)return;

            if(rangeStart<=nodeStart&&rangeEnd>=nodeEnd) {
                node->lazy++;
                node->maxOverlap++;
                return;
            }

            int mid=nodeStart+(nodeEnd-nodeStart)/2;

            if(!node->left)node->left=new SegmentTreeNode();
            if(!node->right)node->right=new SegmentTreeNode();

            //propagate
            if(node->lazy>0) {
                node->left->lazy+=node->lazy;
                node->left->maxOverlap+=node->lazy;
                node->right->lazy+=node->lazy;
                node->right->maxOverlap+=node->lazy;
                node->lazy=0;
            }

            update(node->left,nodeStart,mid,rangeStart,rangeEnd);
            update(node->right,mid,nodeEnd,rangeStart,rangeEnd);

            node->maxOverlap=max(node->left->maxOverlap,node->right->maxOverlap);
        }

        int getMaxOverlap() {
            return root->maxOverlap;
        }
    };
