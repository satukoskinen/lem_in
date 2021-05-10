Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ms/call  ms/call  name    
 33.85      0.45     0.45                             arr_find_by
 32.34      0.88     0.43                             graph_cmp_nodes
 27.83      1.25     0.37                             arr_get
  1.50      1.27     0.02   312748     0.00     0.00  edge_remaining_capacity
  1.50      1.29     0.02                             s_cmp
  0.75      1.30     0.01      435     0.02     0.02  save_flow_path
  0.75      1.31     0.01                             arr_get_last
  0.75      1.32     0.01                             ft_strjoin
  0.75      1.33     0.01                             parse
  0.00      1.33     0.00    28318     0.00     0.00  init_edge_attr
  0.00      1.33     0.00    10605     0.00     0.00  reverse_edge
  0.00      1.33     0.00    10491     0.00     0.00  init_node_attr
  0.00      1.33     0.00     7116     0.00     0.00  print_string
  0.00      1.33     0.00     7056     0.00     0.00  parse_line
  0.00      1.33     0.00     6475     0.00     0.00  get_edge
  0.00      1.33     0.00     3869     0.00     0.00  add_move_to_line
  0.00      1.33     0.00     3761     0.00     0.00  move_ant_from_prev
  0.00      1.33     0.00     3554     0.00     0.00  parse_link
  0.00      1.33     0.00     3498     0.00     0.00  parse_room
  0.00      1.33     0.00     3497     0.00     0.00  split_edge
  0.00      1.33     0.00     3497     0.00     0.00  split_node
  0.00      1.33     0.00     3497     0.00     0.00  validate_coordinates
  0.00      1.33     0.00      435     0.00     0.00  insert_path_to_array
  0.00      1.33     0.00      305     0.00     0.00  move_ants_in_path
  0.00      1.33     0.00      108     0.00     0.00  move_ant_from_source
  0.00      1.33     0.00       61     0.00     0.00  save_round_to_line
  0.00      1.33     0.00       30     0.00     0.67  graph_bfs_loop
  0.00      1.33     0.00       30     0.00     0.00  lem_compare_nodes
  0.00      1.33     0.00       30     0.00     0.67  new_augmenting_flow
  0.00      1.33     0.00       30     0.00     0.00  update_edge_flows
  0.00      1.33     0.00       29     0.00     0.34  save_max_flow_paths
  0.00      1.33     0.00        7     0.00     0.00  add_remaining_ants
  0.00      1.33     0.00        7     0.00     0.00  get_path_cost
  0.00      1.33     0.00        7     0.00     0.00  optimise_ants_per_path
  0.00      1.33     0.00        7     0.00     0.00  optimise_i_paths
  0.00      1.33     0.00        2     0.00     0.00  init_graph
  0.00      1.33     0.00        2     0.00     0.00  parse_command
  0.00      1.33     0.00        2     0.00     0.00  update_graph_attr
  0.00      1.33     0.00        1     0.00    30.01  find_max_flow_paths
  0.00      1.33     0.00        1     0.00     0.00  lem_transform_vertex_disjoint
  0.00      1.33     0.00        1     0.00    30.01  max_flow_edmonds_karp
  0.00      1.33     0.00        1     0.00     0.00  move_ants
  0.00      1.33     0.00        1     0.00     0.00  optimise_path_use
  0.00      1.33     0.00        1     0.00     0.00  parse_ant_count
  0.00      1.33     0.00        1     0.00     0.00  parse_input
  0.00      1.33     0.00        1     0.00    30.01  process_graph

 %         the percentage of the total running time of the
time       program used by this function.

cumulative a running sum of the number of seconds accounted
 seconds   for by this function and those listed above it.

 self      the number of seconds accounted for by this
seconds    function alone.  This is the major sort for this
           listing.

calls      the number of times this function was invoked, if
           this function is profiled, else blank.

 self      the average number of milliseconds spent in this
ms/call    function per call, if this function is profiled,
	   else blank.

 total     the average number of milliseconds spent in this
ms/call    function and its descendents per call, if this
	   function is profiled, else blank.

name       the name of the function.  This is the minor sort
           for this listing. The index shows the location of
	   the function in the gprof listing. If the index is
	   in parenthesis it shows where it would appear in
	   the gprof listing if it were to be printed.

Copyright (C) 2012-2020 Free Software Foundation, Inc.

Copying and distribution of this file, with or without modification,
are permitted in any medium without royalty provided the copyright
notice and this notice are preserved.

		     Call graph (explanation follows)


granularity: each sample hit covers 2 byte(s) for 0.75% of 1.33 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]     33.8    0.45    0.00                 arr_find_by [1]
-----------------------------------------------
                                                 <spontaneous>
[2]     32.3    0.43    0.00                 graph_cmp_nodes [2]
-----------------------------------------------
                                                 <spontaneous>
[3]     27.8    0.37    0.00                 arr_get [3]
-----------------------------------------------
                0.00    0.03       1/1           process_graph [6]
[4]      2.3    0.00    0.03       1         find_max_flow_paths [4]
                0.00    0.03       1/1           max_flow_edmonds_karp [5]
-----------------------------------------------
                0.00    0.03       1/1           find_max_flow_paths [4]
[5]      2.3    0.00    0.03       1         max_flow_edmonds_karp [5]
                0.00    0.02      30/30          new_augmenting_flow [10]
                0.00    0.01      29/29          save_max_flow_paths [13]
                0.00    0.00      30/30          update_edge_flows [35]
-----------------------------------------------
                0.00    0.03       1/1           main [7]
[6]      2.3    0.00    0.03       1         process_graph [6]
                0.00    0.03       1/1           find_max_flow_paths [4]
                0.00    0.00       1/1           lem_transform_vertex_disjoint [43]
                0.00    0.00       1/1           optimise_path_use [45]
                0.00    0.00       1/1           move_ants [44]
-----------------------------------------------
                                                 <spontaneous>
[7]      2.3    0.00    0.03                 main [7]
                0.00    0.03       1/1           process_graph [6]
                0.00    0.00       1/2           init_graph [40]
                0.00    0.00       1/1           parse_input [47]
-----------------------------------------------
                0.02    0.00  312748/312748      graph_bfs_loop [9]
[8]      1.5    0.02    0.00  312748         edge_remaining_capacity [8]
-----------------------------------------------
                              102999             graph_bfs_loop [9]
                0.00    0.02      30/30          new_augmenting_flow [10]
[9]      1.5    0.00    0.02      30+102999  graph_bfs_loop [9]
                0.02    0.00  312748/312748      edge_remaining_capacity [8]
                              102999             graph_bfs_loop [9]
-----------------------------------------------
                0.00    0.02      30/30          max_flow_edmonds_karp [5]
[10]     1.5    0.00    0.02      30         new_augmenting_flow [10]
                0.00    0.02      30/30          graph_bfs_loop [9]
-----------------------------------------------
                                                 <spontaneous>
[11]     1.5    0.02    0.00                 s_cmp [11]
-----------------------------------------------
                0.01    0.00     435/435         save_max_flow_paths [13]
[12]     0.8    0.01    0.00     435         save_flow_path [12]
-----------------------------------------------
                0.00    0.01      29/29          max_flow_edmonds_karp [5]
[13]     0.8    0.00    0.01      29         save_max_flow_paths [13]
                0.01    0.00     435/435         save_flow_path [12]
                0.00    0.00     435/435         insert_path_to_array [30]
-----------------------------------------------
                                                 <spontaneous>
[14]     0.8    0.01    0.00                 arr_get_last [14]
-----------------------------------------------
                                                 <spontaneous>
[15]     0.8    0.01    0.00                 ft_strjoin [15]
-----------------------------------------------
                                                 <spontaneous>
[16]     0.8    0.01    0.00                 parse [16]
-----------------------------------------------
                0.00    0.00    7108/28318       parse_link [25]
                0.00    0.00   21210/28318       reverse_edge [18]
[17]     0.0    0.00    0.00   28318         init_edge_attr [17]
-----------------------------------------------
                0.00    0.00    3497/10605       split_node [28]
                0.00    0.00    7108/10605       split_edge [27]
[18]     0.0    0.00    0.00   10605         reverse_edge [18]
                0.00    0.00   21210/28318       init_edge_attr [17]
-----------------------------------------------
                0.00    0.00    3497/10491       parse_room [26]
                0.00    0.00    6994/10491       split_node [28]
[19]     0.0    0.00    0.00   10491         init_node_attr [19]
-----------------------------------------------
                0.00    0.00    7116/7116        parr_iter [153]
[20]     0.0    0.00    0.00    7116         print_string [20]
-----------------------------------------------
                0.00    0.00    7056/7056        parse_input [47]
[21]     0.0    0.00    0.00    7056         parse_line [21]
                0.00    0.00    3553/3554        parse_link [25]
                0.00    0.00    3498/3498        parse_room [26]
                0.00    0.00       2/2           parse_command [41]
-----------------------------------------------
                0.00    0.00    6475/6475        update_edge_flows [35]
[22]     0.0    0.00    0.00    6475         get_edge [22]
-----------------------------------------------
                0.00    0.00    3869/3869        move_ants_in_path [31]
[23]     0.0    0.00    0.00    3869         add_move_to_line [23]
-----------------------------------------------
                0.00    0.00    3761/3761        move_ants_in_path [31]
[24]     0.0    0.00    0.00    3761         move_ant_from_prev [24]
-----------------------------------------------
                0.00    0.00       1/3554        parse_room [26]
                0.00    0.00    3553/3554        parse_line [21]
[25]     0.0    0.00    0.00    3554         parse_link [25]
                0.00    0.00    7108/28318       init_edge_attr [17]
-----------------------------------------------
                0.00    0.00    3498/3498        parse_line [21]
[26]     0.0    0.00    0.00    3498         parse_room [26]
                0.00    0.00    3497/3497        validate_coordinates [29]
                0.00    0.00    3497/10491       init_node_attr [19]
                0.00    0.00       2/2           update_graph_attr [42]
                0.00    0.00       1/3554        parse_link [25]
-----------------------------------------------
                0.00    0.00    3497/3497        map_parse [140]
[27]     0.0    0.00    0.00    3497         split_edge [27]
                0.00    0.00    7108/10605       reverse_edge [18]
-----------------------------------------------
                0.00    0.00    3497/3497        map_parse [140]
[28]     0.0    0.00    0.00    3497         split_node [28]
                0.00    0.00    6994/10491       init_node_attr [19]
                0.00    0.00    3497/10605       reverse_edge [18]
-----------------------------------------------
                0.00    0.00    3497/3497        parse_room [26]
[29]     0.0    0.00    0.00    3497         validate_coordinates [29]
-----------------------------------------------
                0.00    0.00     435/435         save_max_flow_paths [13]
[30]     0.0    0.00    0.00     435         insert_path_to_array [30]
-----------------------------------------------
                0.00    0.00     305/305         save_round_to_line [33]
[31]     0.0    0.00    0.00     305         move_ants_in_path [31]
                0.00    0.00    3869/3869        add_move_to_line [23]
                0.00    0.00    3761/3761        move_ant_from_prev [24]
                0.00    0.00     108/108         move_ant_from_source [32]
-----------------------------------------------
                0.00    0.00     108/108         move_ants_in_path [31]
[32]     0.0    0.00    0.00     108         move_ant_from_source [32]
-----------------------------------------------
                0.00    0.00      61/61          move_ants [44]
[33]     0.0    0.00    0.00      61         save_round_to_line [33]
                0.00    0.00     305/305         move_ants_in_path [31]
-----------------------------------------------
                0.00    0.00      30/30          update_edge_flows [35]
[34]     0.0    0.00    0.00      30         lem_compare_nodes [34]
-----------------------------------------------
                0.00    0.00      30/30          max_flow_edmonds_karp [5]
[35]     0.0    0.00    0.00      30         update_edge_flows [35]
                0.00    0.00    6475/6475        get_edge [22]
                0.00    0.00      30/30          lem_compare_nodes [34]
-----------------------------------------------
                0.00    0.00       7/7           optimise_ants_per_path [38]
[36]     0.0    0.00    0.00       7         add_remaining_ants [36]
-----------------------------------------------
                0.00    0.00       7/7           optimise_ants_per_path [38]
[37]     0.0    0.00    0.00       7         get_path_cost [37]
-----------------------------------------------
                0.00    0.00       7/7           optimise_i_paths [39]
[38]     0.0    0.00    0.00       7         optimise_ants_per_path [38]
                0.00    0.00       7/7           add_remaining_ants [36]
                0.00    0.00       7/7           get_path_cost [37]
-----------------------------------------------
                0.00    0.00       7/7           optimise_path_use [45]
[39]     0.0    0.00    0.00       7         optimise_i_paths [39]
                0.00    0.00       7/7           optimise_ants_per_path [38]
-----------------------------------------------
                0.00    0.00       1/2           main [7]
                0.00    0.00       1/2           lem_transform_vertex_disjoint [43]
[40]     0.0    0.00    0.00       2         init_graph [40]
-----------------------------------------------
                0.00    0.00       2/2           parse_line [21]
[41]     0.0    0.00    0.00       2         parse_command [41]
-----------------------------------------------
                0.00    0.00       2/2           parse_room [26]
[42]     0.0    0.00    0.00       2         update_graph_attr [42]
-----------------------------------------------
                0.00    0.00       1/1           process_graph [6]
[43]     0.0    0.00    0.00       1         lem_transform_vertex_disjoint [43]
                0.00    0.00       1/2           init_graph [40]
-----------------------------------------------
                0.00    0.00       1/1           process_graph [6]
[44]     0.0    0.00    0.00       1         move_ants [44]
                0.00    0.00      61/61          save_round_to_line [33]
-----------------------------------------------
                0.00    0.00       1/1           process_graph [6]
[45]     0.0    0.00    0.00       1         optimise_path_use [45]
                0.00    0.00       7/7           optimise_i_paths [39]
-----------------------------------------------
                0.00    0.00       1/1           parse_input [47]
[46]     0.0    0.00    0.00       1         parse_ant_count [46]
-----------------------------------------------
                0.00    0.00       1/1           main [7]
[47]     0.0    0.00    0.00       1         parse_input [47]
                0.00    0.00    7056/7056        parse_line [21]
                0.00    0.00       1/1           parse_ant_count [46]
-----------------------------------------------

 This table describes the call tree of the program, and was sorted by
 the total amount of time spent in each function and its children.

 Each entry in this table consists of several lines.  The line with the
 index number at the left hand margin lists the current function.
 The lines above it list the functions that called this function,
 and the lines below it list the functions this one called.
 This line lists:
     index	A unique number given to each element of the table.
		Index numbers are sorted numerically.
		The index number is printed next to every function name so
		it is easier to look up where the function is in the table.

     % time	This is the percentage of the `total' time that was spent
		in this function and its children.  Note that due to
		different viewpoints, functions excluded by options, etc,
		these numbers will NOT add up to 100%.

     self	This is the total amount of time spent in this function.

     children	This is the total amount of time propagated into this
		function by its children.

     called	This is the number of times the function was called.
		If the function called itself recursively, the number
		only includes non-recursive calls, and is followed by
		a `+' and the number of recursive calls.

     name	The name of the current function.  The index number is
		printed after it.  If the function is a member of a
		cycle, the cycle number is printed between the
		function's name and the index number.


 For the function's parents, the fields have the following meanings:

     self	This is the amount of time that was propagated directly
		from the function into this parent.

     children	This is the amount of time that was propagated from
		the function's children into this parent.

     called	This is the number of times this parent called the
		function `/' the total number of times the function
		was called.  Recursive calls to the function are not
		included in the number after the `/'.

     name	This is the name of the parent.  The parent's index
		number is printed after it.  If the parent is a
		member of a cycle, the cycle number is printed between
		the name and the index number.

 If the parents of the function cannot be determined, the word
 `<spontaneous>' is printed in the `name' field, and all the other
 fields are blank.

 For the function's children, the fields have the following meanings:

     self	This is the amount of time that was propagated directly
		from the child into the function.

     children	This is the amount of time that was propagated from the
		child's children to the function.

     called	This is the number of times the function called
		this child `/' the total number of times the child
		was called.  Recursive calls by the child are not
		listed in the number after the `/'.

     name	This is the name of the child.  The child's index
		number is printed after it.  If the child is a
		member of a cycle, the cycle number is printed
		between the name and the index number.

 If there are any cycles (circles) in the call graph, there is an
 entry for the cycle-as-a-whole.  This entry shows who called the
 cycle (as parents) and the members of the cycle (as children.)
 The `+' recursive calls entry shows the number of function calls that
 were internal to the cycle, and the calls entry for each member shows,
 for that member, how many times it was called from other members of
 the cycle.

Copyright (C) 2012-2020 Free Software Foundation, Inc.

Copying and distribution of this file, with or without modification,
are permitted in any medium without royalty provided the copyright
notice and this notice are preserved.

Index by function name

  [23] add_move_to_line (move_ants.c) [34] lem_compare_nodes [25] parse_link
  [36] add_remaining_ants (optimise_path_use.c) [43] lem_transform_vertex_disjoint [26] parse_room
   [1] arr_find_by             [5] max_flow_edmonds_karp  [20] print_string
   [3] arr_get                [24] move_ant_from_prev (move_ants.c) [6] process_graph
  [14] arr_get_last           [32] move_ant_from_source (move_ants.c) [18] reverse_edge (lem_transform_vertex_disjoint.c)
   [8] edge_remaining_capacity (max_flow_edmonds_karp.c) [44] move_ants [11] s_cmp
   [4] find_max_flow_paths    [31] move_ants_in_path (move_ants.c) [12] save_flow_path
  [15] ft_strjoin             [10] new_augmenting_flow    [13] save_max_flow_paths
  [22] get_edge               [38] optimise_ants_per_path (optimise_path_use.c) [33] save_round_to_line
  [37] get_path_cost (optimise_path_use.c) [39] optimise_i_paths (optimise_path_use.c) [27] split_edge (lem_transform_vertex_disjoint.c)
   [9] graph_bfs_loop (max_flow_edmonds_karp.c) [45] optimise_path_use [28] split_node (lem_transform_vertex_disjoint.c)
   [2] graph_cmp_nodes        [16] parse                  [35] update_edge_flows
  [17] init_edge_attr         [46] parse_ant_count (parse_input.c) [42] update_graph_attr (parse_room.c)
  [40] init_graph             [41] parse_command (parse_line.c) [29] validate_coordinates (parse_room.c)
  [19] init_node_attr         [47] parse_input
  [30] insert_path_to_array (save_max_flow_paths.c) [21] parse_line
