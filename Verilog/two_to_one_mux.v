// Lab4 part 2
// 2:1 Mux 8 bit wide
// Inputs - x,y and s
// x - 8 bit wide input
// y - 8 bit wide input
// s - 1 bit wide select line
// m - 8 bit wide output
module two_to_one_mux(
	x,
	y,
	s,
	m);

parameter WIDTH = 3; 			// Set the mux width for Part 2
					// For 8 bit wide signal the bits run from 7 down to 0
input [WIDTH-1 : 0] x; 			// This is why we have WIDTH-1
							
input [WIDTH-1 : 0] y; 			// Declare y			
input s; 				// Declare s, note s is 1 bit signal because this is a 2:1 mux
output reg [WIDTH-1 : 0] m; 		// Declare m 

// This is where we implement the 2:1 Mux logic
// Use if else to assign values of x or y to m
// s  |  m
// -------
// 0  |  x
// 1  |  y


always@(*) begin
  if(s == 0)// Add condition for Mux
    m = x;
  else 
    m = y;
end
endmodule
