(function ($) {

  /**
   * Set active class on Views AJAX filter
   * on selected category
   */
  Drupal.behaviors.EarthMatters = {
    attach: function (context, settings) {

      var view = $('.earth-matters-listing.news-list');

      /**
       * Set the view filter value in the select.
       */
      function setFilter(value, filter) {
        if ($(filter).attr('multiple')) {
          var existingValues = $(filter).val();

          if (existingValues) {
            var i = existingValues.indexOf(value);

            if (i !== -1) {
              delete existingValues[i];
            }
            else {
              existingValues.push(value);
            }
            value = existingValues;
          }
          else {
            value = [value];
          }

          if (value.length) {
            value = cleanArray(value);
          }
        }

        filter.val(value);
        $(filter).trigger('change');

        refreshViews();
      }

      /**
       * Clean the string to make a url friendly string.
       */
      function cleanString(string) {
        string = string.replace(/[^a-zA-Z0-9]+/g, '-').toLowerCase().replace(' ', '-');
        while (string.indexOf('--') != -1) {
          string = string.replace('--', '-');
        }
        return string;
      }

      /**
       * Remove empty values in array like array_filter() in PHP.
       */
      function cleanArray(actual) {
        var newArray = [];
        for (var i = 0; i < actual.length; i++) {
          if (actual[i]) {
            newArray.push(actual[i]);
          }
        }
        return newArray;
      }

      /**
       * Reload the view contents.
       */
      function refreshViews() {
        var views = settings.views.ajaxViews;

        $.each(views, function (i, view) {
          var dom_id = view.view_dom_id;
          var selector = '.js-view-dom-id-' + dom_id;
          var args = [];
          if ($(selector).find('select').val()) {
            args = $(selector).find('select').val().join('+');
          }
          settings.views.ajaxViews['views_dom_id:' + dom_id].view_args = args;
          $(selector).triggerHandler('RefreshView');
        });
      }

      /**
       * Set the filter click listener.
       */
      function setFilterClick(element, view) {
        if ($(element).hasClass('filterClickProcessed')) {
          return;
        }

        $(element).on('click', function (e) {
          e.preventDefault();
          $(this).parent().toggleClass('active');

          var tid = $(this).attr('data-tid');
          if (!tid) {
            tid = $(this).attr('rel');
          }
          var filter = $(view).find('select');

          setPushState($(this).text());


          setFilter(tid, filter);
        }).addClass('filterClickProcessed');
      }

      /**
       * Push the new url with new filters to the browser.
       */
      function setPushState(string) {
        var current_path = window.location.pathname;
        string = cleanString(string);
        if (current_path.indexOf(string) == -1) {
          current_path = current_path + '/' + string;
        }
        else {
          current_path = current_path.replace('/' + string, '');
        }

        history.pushState(null, null, current_path + window.location.search + window.location.hash);
      }

      $(view).find('a.filter-tab, .masonry-block__tags .tag-item').each(function () {
        setFilterClick(this, view);
      });
    },

    /**
     * Set active classes based on the arguments from the view.
     */
    setActives: function () {
      $.each(Drupal.views.instances, function (i, view) {
        if (view.settings.view_args) {
          $.each(view.settings.view_args.split('+'), function (j, value) {
            $('a[data-tid="' + value + '"]').parent().addClass('active');
            $('a[rel="' + value + '"]').addClass('active');
          })
        }
      });
    }
  };


  $(document).ajaxComplete(Drupal.behaviors.EarthMatters.setActives);
  Drupal.behaviors.EarthMatters.setActives();


})(jQuery);
