# event_sort

This is an example implementation of a custom Drupal views sort handler. See [my blog post](https://evolvingweb.ca/blog/custom-views-sort-plugin-for-upcoming-events) for more details.

It's meant to sort events in a way that shows users the most interesting events first:

* Future events come before past events
* Events closest to today come before events far in the past or future

![Correctly sorted view](https://evolvingweb.ca/sites/default/files/inline-images/views-sort-blog-post_1.png)

## Usage

Note that this is a sample of a custom module. The [hook_views_data_alter()](event_sort.views.inc#L11) assumes the field name is `field_event_date`, but that's unlikely to be the right field for your site.

However, the sort handler is generic, so you could easily write a custom hook_views_data_alter() that applies it to a different field or property.
