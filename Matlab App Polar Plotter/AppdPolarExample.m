%% Polar Plotting App in App Designer
% This app shows how to display a plot by creating the axes programmatically 
% before calling a plotting function. In this case, the app plots a polar equation 
% using the <docid:matlab_ref#buyrm5i> and <docid:matlab_ref#buyrm3v> functions. 
% When the user changes the value of _a_ or _b_, or when they select a different line color, 
% the plot updates to reflect their changes. 
%
% This example also demonstrates the following app building concepts:
%
% * Creating different types of axes programmatically to display plots that |uiaxes| does not support
% * Calling a plotting function in App Designer
% * Sharing a callback with multiple components
% * Displaying Unicode(R) characters in a label
%
% <<../polar_app_screenshot.png>>

% Copyright 2018 The MathWorks, Inc.