#ifndef GRAPH_H
#define _GRAPH_H
#define  DEFAULT_VERTEX_SIZE 10
#include<string.h>
#include<queue>
template<class Type>
class Graph;
class Edge
{
		public:
				Edge(int num):dest(num),link(NULL)
		{}
				~Edge()
				{}
				int dest;
				Edge* link;
};
template<class Type>
class Vertex
{
		friend Graph<Type>;
		public:
		Vertex():data(Type()),adj(NULL)
		{}
		~Vertex()
		{}
		private:
		Edge *adj;
		Type data;
};
template<class Type>
class Graph
{
		public:
				Graph(int sz=DEFAULT_VERTEX_SIZE)
				{
						MaxVertices=sz>DEFAULT_VERTEX_SIZE?sz:DEFAULT_VERTEX_SIZE;
						NumVertices=NumEdge=0;
						NodeTable=new Vertex<Type>[MaxVertices];
				}
				~Graph()
				{
						Edge *t;
						for(int i=0;i<NumVertices;++i)
						{
								Edge *w;
								t=NodeTable[i].adj;
								while(t!=NULL)
								{
										w=t;
										t=t->link;
										delete w;
								}
						}
						delete[] NodeTable;

						//////
				}
				int GetPosOfVertex(const Type &v)const
				{
						for(int i=0;i<NumVertices;++i)
						{
								if(NodeTable[i].data==v)
										return i;
						}
						return -1;

				}
				void InsertVertex(const Type &val)
				{
						if(NumVertices<MaxVertices)
						{
								NodeTable[NumVertices++].data=val;
						}
				}
				bool InsertEdge(const Type &vertex1, const Type &vertex2)
				{
						int v1 = GetPosOfVertex(vertex1);
						int v2 = GetPosOfVertex(vertex2);
						if(v1==-1 || v2==-1)
								return false;
						//v1 --> v2
						Edge *e = new Edge(v2);
						e->link = NodeTable[v1].adj;
						NodeTable[v1].adj = e;
						//v2 --> v1
						e = new Edge(v1);
						e->link = NodeTable[v2].adj;
						NodeTable[v2].adj = e;
						NumEdge++;
						return true;
				}

				/*
				   bool InsertEdge(const Type &v1,const Type &v2)
				   {
				   int V1=GetPosOfVertex(v1);
				   int V2=GetPosOfVertex(v2);
				   if(V1==-1||V2==-1)
				   return false;
				//v1-->v2
				cout<<"v1: "<<V1<<"  v2:  "<<V2<<endl;
				Edge *s=new Edge(V2);
				s->link=NodeTable[V1].adj;
				NodeTable[V1].adj=s;
				//v2-->v1
				Edge *s1=new Edge(V1);
				s1->link=NodeTable[V2].adj;
				NodeTable[V1].adj=s1;
				++NumEdge;
				return true;
				}
				 */
				int NumOfVertex()const
				{
						return NumVertices;
				}
				int NumOfEdge()const
				{
						return NumEdge;
				}
				Type GetValueByIndex(int i)
				{
						if(i<=NumVertices&&i>=0)
								return NodeTable[i].data;
				}
				int GetFirstNeighbor(const Type &vertex)const
				{
						int v=GetPosOfVertex(vertex);
						if(v==-1)
								return -1;
						if(    NodeTable[v].adj!=NULL)
								return NodeTable[v].adj->dest;
						else
								return -1;

				}
				int GetNextNeighbor(const Type &vertex1,const Type &vertex2)const
				{
						int v1=GetPosOfVertex(vertex1);
						int v2=GetPosOfVertex(vertex2);
						if(v1==-1||v2==-1)
								return -1;
						if(NodeTable[v1].adj==NULL)
								return -1;
						Edge *t=NodeTable[v1].adj;
						while(t!=NULL&&t->dest!=v2)
								t=t->link;
						if(t==NULL)
								return -1;
						else
								if(t->link!=NULL)
										return t->link->dest;
								else
										return -1;
				}

				bool RemoveEdge(const Type &vertex1,const Type &vertex2)
				{
						int v1=GetPosOfVertex(vertex1);
						int v2=GetPosOfVertex(vertex2);
						if(v1==-1||v2==-1)
								return false;
						Edge *t=NodeTable[v1].adj;
						Edge *p=t;
						while(t!=NULL&&t->dest!=v2)
						{
								p=t;
								t=t->link;
						}
						if(t==NULL)
								return false;
						else
						{
								if(p==t)
								{
										Edge *w=NodeTable[v1].adj;
										NodeTable[v1].adj=NodeTable[v1].adj->link;
										delete w;
								}
								else
								{
										Edge *w=p->link;
										p->link=t->link;
										delete w;
								}
								//
								t=p=NodeTable[v2].adj;
								while(t->dest!=v1)
								{
										p=t;
										t=t->link;
								}
								if(t==p)
								{
										Edge *w=NodeTable[v2].adj;
										NodeTable[v2].adj=NodeTable[v2].adj->link;
										delete w;
								}
								else
								{    
										Edge *w=p->link;
										p->link=t->link;
										delete w;
								}
								--NumEdge;
								return true;
						}

				}
				bool RemoveVertex(const Type &vertex)
				{
						int v=GetPosOfVertex(vertex);
						if(v==-1)
								return false;
						Edge* t=NodeTable[v].adj;
						while(t!=NULL)
						{
								Edge *p=NodeTable[t->dest].adj;
								Edge *p1=p;
								while(p!=NULL)
								{
										while(p->dest!=v)
										{
												p1=p;
												p=p->link;
										}
										if(p==p1)
										{
												Edge *w=NodeTable[t->dest].adj;
												NodeTable[t->dest].adj=NodeTable[t->dest].adj->link;
												delete w;
												break;
										}
										else
										{
												Edge* w=p1->link;
												p1->link=p->link;
												delete w;
												break;
										}
								}
								p1=t;
								t=t->link;
								delete p1;
								--NumEdge;
						}
						if(v!=NumVertices-1)
						{
								NodeTable[v].data=NodeTable[NumVertices-1].data;
								NodeTable[v].adj=NodeTable[NumVertices-1].adj;
								Edge *t1=NodeTable[NumVertices-1].adj;
								while(t1!=NULL)
								{
										Edge *p3=NodeTable[t1->dest].adj;
										while(p3->dest!=NumVertices-1)
												p3=p3->link;
										p3->dest=v;

										t1=t1->link;
								}
						}
						--NumVertices;
						return true;
				}
				void DFSTraverse()//深度遍历
				{
						bool *visited=new bool[NumVertices];
						for(int i=0;i<NumVertices;++i)
								visited[i]=false;
						cout<<"深度优先搜索树（无向无环图）:"<<endl;
						int count = 1;
						for(int i=0;i<NumVertices;++i)
						{
								if(!visited[i])
								{
										cout<<"	["<<count++<<"]	";
										DFS(i,visited);
								}
						}
				}
				void DFS(int v,bool *&visited)
				{
					static int time = 0;
						if(v<=-1&&v>=NumVertices)
								return ;
						visited[v]=true;
						time = time+1;
						cout<<"("<<NodeTable[v].data<<":"<<time<<"	";
						for(int w=GetFirstNeighbor(GetValueByIndex(v));w>=0;w=GetNextNeighbor(GetValueByIndex(v),GetValueByIndex(w)))
								if(!visited[w])
										DFS(w,visited);
						time = time + 1;
						cout<<NodeTable[v].data<<":"<<time<<")	";
				}
				void DFSTraverse_1(Type val)
				{
						bool *visited=new bool[NumVertices];
						for(int i=0;i<NumVertices;++i)
								visited[i]=false;
						int x=GetPosOfVertex(val);
						visited[x]=true;
						cout<<NodeTable[x].data<<"  ";
						for(int w=GetFirstNeighbor(val);w>=0;w=GetNextNeighbor(val,GetValueByIndex(w)))
						{
								if(!visited[w])
								{
										visited[w]=true;
										cout<<NodeTable[w].data<<"  ";
								}
						}
						for(int i=0;i<NumVertices;++i)
						{
								if(!visited[i])
								{
										visited[i]=true;
										cout<<NodeTable[i].data<<"  ";
										for(int w=GetFirstNeighbor(GetValueByIndex(i));w>=0;w=GetNextNeighbor(GetValueByIndex(i),GetValueByIndex(w)))
												if(!visited[w])
												{
														visited[w]=true;
														cout<<NodeTable[w].data<<"  ";
												}
								}

						}

				}
				void BFSTraverse()//广度遍历
				{
						cout<<"广度优先搜索树：";
						bool *visited=new bool[NumVertices];
						int *distance = new int[NumVertices];
						memset(distance,0,sizeof(int)*NumVertices);
						for(int i=0;i<NumVertices;++i)
								visited[i]=false;
						queue<int>  Q;

						distance[0] = 0;
						for(int i=0;i<NumVertices;++i)
						{
								if(!visited[i])
								{
										visited[i]=true;
										cout<<NodeTable[i].data<<" : depth="<<distance[i]<<"	";
								}
								Q.push(i);
								while(!Q.empty())
								{
										int u=Q.front();
										Q.pop();
										Edge *s=NodeTable[u].adj;
										while(s!=NULL)
										{
												if(!visited[s->dest])
												{
														visited[s->dest]=true;
														Q.push(s->dest);

														distance[s->dest] = distance[u] + 1;
														cout<<NodeTable[s->dest].data<<" : depth="<<distance[s->dest]<<"	";
														
												}
												s=s->link;
										}
								}
						}
				}
				void BFSTraverse_1(Type v)
				{
						bool *visited=new bool[NumVertices];
						queue<int> Q;
						int x=GetPosOfVertex(v);
						if(x==-1)
								return;
						Q.push(x);
						cout<<v<<"  ";
						visited[x]=true;
						Edge *s=NodeTable[x].adj;
						while(s!=NULL)
						{    
								if(!visited[s->dest])
								{
										visited[s->dest]=true;
										Q.push(s->dest);
										cout<<NodeTable[s->dest].data<<"  ";
								}
								s=s->link;
						}
						while(!Q.empty())
						{
								int u=Q.front();
								Q.pop();
								s=NodeTable[u].adj;
								while(s!=NULL)
								{
										if(!visited[s->dest])
										{
												visited[s->dest]=true;
												cout<<NodeTable[s->dest].data<<"  ";
												Q.push(s->dest);
										}
										s=s->link;
								}

						}
				}
				void ShowGraph()
				{
						for(int i=0;i<NumVertices;++i)
						{
								cout<<i<<"  "<<NodeTable[i].data<<"  "<<"-->";
								Edge* e=NodeTable[i].adj;
								while(e!=NULL)
								{
										cout<<e->dest<<"-->";
										e=e->link;
								}
								cout<<"NUL"<<endl;;
						}
				}
		private:
				Vertex<Type>*NodeTable;
				int MaxVertices;
				int NumVertices;
				int NumEdge;
};

#endif

