#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "set.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////
//! \class Graph /////////////////////////////////////////////////////////////////////////////

//! \brief The Graph interface common to every implementation. 
//! \param _GraphImpl : The implementation
//! \param _IndexType : type used to refer to Elements, allow to use safer types than "int"
template<typename _GraphImpl, typename _IndexType = int>
class Graph : protected _GraphImpl {
public:
  typedef typename _GraphImpl::EdgeLabelType EdgeLabelType;
  typedef typename _GraphImpl::VertexLabelType VertexLabelType;
  
  typedef _IndexType VertexIndexType;
  typedef AugmentedPair<_IndexType, _IndexType> EdgeIndexType;

  typedef Graph<typename _GraphImpl::RawImpl, _IndexType> RawGraph;

  template<class _ElementType, typename _LabelType, typename _ElementIndexType> class VirtualList;
  template<typename _LabelType, typename _ElementIndexType> class VirtualElement;

  class Edge;
  class Vertex;

  typedef VirtualList<Edge, EdgeLabelType, EdgeIndexType> EdgeList;
  typedef VirtualList<Vertex, VertexLabelType, VertexIndexType> VertexList;

  //! Allow Edge Ref to modify the graph
  friend class Edge;
  //! Allow Vertex Ref to modify the graph
  friend class Vertex;
  friend EdgeList;
  friend VertexList;

  //! \brief Default Constructor
  inline Graph();

  //! \brief Copy Constructor
  inline Graph(const Graph&);

  //! \brief Copy Operation
  inline Graph& operator=(const Graph&);

  //! \brief Convert Graph into Graph without any label
  inline operator RawGraph();

  //! \brief Operate the union operation with an other Graph
  //! \param other : The graph to make the union with
  //! \return A reference to "this" Graph
  //! \warning The sum of vertices and edges need to be under the maximal capacity of the implementation
  inline Graph& operator|=(const Graph&);

  //! \brief Operate the union operation with an other Graph
  //! \param other : The graph to make the union with
  //! \return A reference to a Graph
  //! \warning The sum of vertices and edges need to be under the maximal capacity of the implementation
  inline Graph operator|(const Graph&) const;

  //! \brief Operate the multiplication operation with a Graph without any label
  //! \param other : The graph to multiply with
  //! \return A reference to "this" Graph
  //! \warning The resulting number of vertices and edges need to be under the maximal capacity of the implementation
  inline Graph& operator*=(const RawGraph&);

  //! \brief Operate the multiplication operation with a Graph without any label
  //! \param other : The graph to multiply with
  //! \return A reference to "this" Graph
  //! \warning The resulting number of vertices and edges need to be under the maximal capacity of the implementation
  inline Graph operator*(const RawGraph&);

  //! \brief Returns the Edge List to allow to add, remove or access Edges
  inline EdgeList edges(void);

  //! \brief Returns the Vertices List to allow to add, remove or access Vertices
  inline VertexList vertices(void);
};

//////////////////////////////////////////////////////////////////////////////////////////////
//! \class Graph::VirtualList //////////////////////////////////////////////////////////////////

//! \brief A list interface for Graph's Edges or Vertices
template<class _GraphImpl, typename _IndexType>
template<class _ElementType, typename _LabelType, typename _ElementIndexType>
class Graph<_GraphImpl, _IndexType>::VirtualList {
  //! Allow the parent Graph to call it's protected constructor
  friend Graph;

protected:
  //! \brief The constructor to be used when constructed in Graph
  inline VirtualList(Graph&);

  //! \brief The parent Graph
  Graph& graph;

public:
  //! \brief Copy Constructor
  inline VirtualList(const VirtualList&);

  //! \brief Copy Operation
  inline VirtualList& operator=(const VirtualList&);

  //! \brief Adds an element to the Graph (in the case of void label)
  //! \return The index of the created element
  inline _ElementIndexType add(void);

  //! \brief Adds an element to the Graph with the specified label
  //! \param label : The label to associate to the new created Element (Caution ! Need to be of the right type)
  //! \return The index of the created element
  template<typename LabelType> inline _ElementIndexType add(const LabelType&);

  //! \brief Return the Element (Vertex or Edge) with the specified index
  //! \param index : The index of the required element
  //! \return The required element
  inline _ElementType get(_ElementIndexType);

  //! \brief Remove the element with the specified index from the Graph
  //! \param index : The index of the element to remove
  inline void remove(_ElementIndexType);
  
  //! \brief Execute a function on each element of the list
  //! \param func : The function to be executed. Takes in paramerter a reference to the Element.
  template<typename Callable> inline void foreach(const Callable&);
};

//////////////////////////////////////////////////////////////////////////////////////////////
//! \class Graph::VirtualElement ///////////////////////////////////////////////////////////////

//! \brief Interface for Graph's Edges and Vertices references
template<typename _GraphImpl, typename _IndexType>
template<typename _LabelType, typename _ElementIndexType>
class Graph<_GraphImpl, _IndexType>::VirtualElement {
protected:
  //! \brief The constructor to be used when constructed in the Graph
  inline VirtualElement(Graph&, _ElementIndexType);
  
  //! \brief The parent Graph
  Graph& graph;
  //! \brief The element Id
  _ElementIndexType id;

public:
  //! \brief Copy Constructor
  inline VirtualElement(const VirtualElement&);
  //! \brief Copy Operator
  inline VirtualElement& operator=(const VirtualElement&);

  //! \brief Return the Element's label
  inline _LabelType& label(void);

  //! \brief Return the Element's index
  inline _ElementIndexType index(void);
};

//! \brief Specialisation  of VirtualElement when there is no label
template<typename _GraphImpl, typename _IndexType>
template<typename _ElementIndexType>
class Graph<_GraphImpl, _IndexType>::VirtualElement<void, _ElementIndexType> {
protected:
  //! \brief The constructor to be used when constructed in the Graph
  inline VirtualElement(Graph<_GraphImpl, _IndexType>&, _ElementIndexType);
  
  //! \brief The parent Graph
  Graph<_GraphImpl, _IndexType>& graph;
  //! \brief The element Id
  _ElementIndexType id;

public:
  //! \brief Copy Constructor
  inline VirtualElement(const VirtualElement&);
  //! \brief Copy Operator
  inline VirtualElement& operator=(const VirtualElement&);

  //! \brief Return the Element's index
  inline _ElementIndexType index(void);
};

//////////////////////////////////////////////////////////////////////////////////////////////
//! \class Graph::Vertex //////////////////////////////////////////////////

//! \brief A Graph's Vertex reference
template<typename _GraphImpl, typename _IndexType = int>
class Graph<_GraphImpl, _IndexType>::Vertex : 
  public VirtualElement<VertexLabelType, VertexIndexType> {
  //! To allow VertexList to call the protected constructor
  friend typename Graph<_GraphImpl, _IndexType>::VertexList;

protected:
  //! \brief The constructor to be used when constructed in the Graph
  inline Vertex(Graph<_GraphImpl, _IndexType>&, VertexIndexType);

public:
  //! \brief Copy Constructor
  inline Vertex(const Vertex&);
  //! \brief Copy Operator
  inline Vertex& operator=(const Vertex&);

  //! \brief Execute a function on each Children Vertex
  //! \param func : A function taking in parameter a Vertex reference
  template<typename Callable> inline void foreachChildren(const Callable&);
  //! \brief Execute a function on each Parent Vertex
  //! \param func : A function taking in parameter a Vertex reference
  template<typename Callable> inline void foreachParent(const Callable&);
  //! \brief Execute a function on each Out going Edge
  //! \param func : A function taking in parameter an Edge reference
  template<typename Callable> inline void foreachOut(const Callable&);
  //! \brief Execute a function on each In coming Edge
  //! \param func : A function taking in parameter an Edge reference
  template<typename Callable> inline void foreachIn(const Callable&);
};

//////////////////////////////////////////////////////////////////////////////////////////////
//! \class Graph::Edge ////////////////////////////////////////////////////

//! \brief A Graph's Edge reference
template<typename _GraphImpl, typename _IndexType = int>
class Graph<_GraphImpl, _IndexType>::Edge : 
  public VirtualElement<EdgeLabelType, EdgeIndexType> {
  //! To allow EdgeList to call the protected constructor
  friend typename Graph<_GraphImpl, _IndexType>::EdgeList;

protected:
  //! \brief The constructor to be used when constructed in the Graph
  inline Edge(Graph<_GraphImpl, _IndexType>&, EdgeIndexType);

public:
  //! \brief Copy Constructor
  inline Edge(const Edge&);
  //! \brief Copy Operator
  inline Edge& operator=(const Edge&);
  
  //! \brief Returns the target Vertex (in case of directed Graph), or one incident Vertex (undirected case)
  inline Vertex target(void);
  //! \brief Returns the source Vertex (in case of directed Graph), or one incident Vertex (undirected case)
  inline Vertex source(void);
};

//////////////////////////////////////////////////////////////////////////////////////////////
//! \class GraphImpl /////////////////////////////////////////////////////////////////////////

//! \brief Defines basic types for use in Graph class
template<typename _EdgeType, typename _VertexType>
class GraphImpl {
public:
  typedef _EdgeType EdgeLabelType;
  typedef _VertexType VertexLabelType;
};

#endif//GRAPH_HPP
