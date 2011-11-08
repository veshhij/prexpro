function J = computeCost(X, y, theta)
%COMPUTECOST Compute cost for linear regression
%   J = COMPUTECOST(X, y, theta) computes the cost of using theta as the
%   parameter for linear regression to fit the data points in X and y

% Initialize some useful values
m = length(y); % number of training examples

% You need to return the following variables correctly 
J = 0;

% ====================== YOUR CODE HERE ======================
% Instructions: Compute the cost of a particular choice of theta
%               You should set J to the cost.

theta_1 = theta( 1 );
theta_2 = theta( 2 );

for iter = 1:m
    J = J + ( theta_1 * X( iter, 1 ) + theta_2 * X( iter, 2 ) - y( iter ) ) ^ 2;
end

J = J / ( 2 * m );

% =========================================================================

end
