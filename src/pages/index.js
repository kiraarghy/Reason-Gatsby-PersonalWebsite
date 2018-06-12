import React from 'react'
import Link from 'gatsby-link'
import Body from '../../lib/js/src/components/body.bs.js'
import Footer from '../../lib/js/src/components/footer.bs.js'
import Content from '../../lib/js/src/components/content.bs.js'
import './index.css'

const IndexPage = data => {
  console.log(data)
  return (
    <div className="page">
      <Body data={data.data} />
      <Content data={data.data} />
      <div className="work" />
      <Footer data={data.data} />
    </div>
  )
}

export default IndexPage

export const query = graphql`
  query blah {
    contentfulAbout {
      name
      portrait {
        description
        file {
          url
        }
      }
      markdown {
        markdown
      }
      builtUsing {
        title
        file {
          url
        }
      }
    }
  }
`
