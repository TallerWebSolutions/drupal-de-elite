CKEDITOR.plugins.add( 'geshi',
{
  requires: [ 'styles', 'button' ],

  init : function( editor ) {
    // All buttons use the same code to register. So, to avoid
    // duplications, let's use this tool function.
    var addButtonCommand = function( buttonName, buttonLabel, commandName, styleDefiniton ) {
      var style = new CKEDITOR.style( styleDefiniton );

      editor.attachStyleStateChange( style, function( state ) {
        editor.getCommand( commandName ).setState( state );
      });

      editor.addCommand( commandName, new CKEDITOR.styleCommand( style ));

      editor.ui.addButton( buttonName, {
        label : buttonLabel,
        command : commandName
      });
    };

    // add buttons for all active geshi filters
    for (var filter in Drupal.settings.wysiwygGeshi) {
      addButtonCommand(filter, Drupal.settings.wysiwygGeshi[filter].label, filter, Drupal.settings.wysiwygGeshi[filter].settings);
    }
  }
});
